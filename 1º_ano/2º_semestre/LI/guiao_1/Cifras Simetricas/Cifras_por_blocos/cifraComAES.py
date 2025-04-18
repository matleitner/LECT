from Cryptodome.Cipher import AES
import sys
import hashlib
import os
def pad_manual(data, block_size=16):
    padding_length = block_size - (len(data) % block_size)
    if padding_length == 0:
        padding_length = block_size
    padding = bytes([padding_length] * padding_length)
    return data + padding



def encodeAES(filename):
    key = sys.argv[2]
    
    if len(key)<16:
        chave_sintetizada = hashlib.sha256(key.encode()).digest()        
        key = chave_sintetizada[:16]
    elif len(key) == 16 or len(key) == 24 or len(key) == 32:
        key = key.encode()
    else:
        key = key[:16].encode()

    # print(key)
    cipher = AES.new(key, AES.MODE_ECB)
    # print(cipher.block_size)

    with open(filename, "rb") as f:
        buffer = f.read(512)
        if len(buffer)%16!=0:
            buffer = pad_manual(buffer)

        x = cipher.encrypt(buffer)
        os.write(1,x)        
        while len(buffer) > 0:
            buffer = f.read(512);
            if len(buffer)%16!=0:
                buffer = pad_manual(buffer)
            x = cipher.encrypt(buffer)
            os.write(1,x)       
encodeAES(sys.argv[1])