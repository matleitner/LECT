from Cryptodome.Cipher import AES
import sys
import hashlib
import os
def unpad_manual(data):
    padding_length = data[-1]  
    return data[:-padding_length]


def decodeAES(filename):
    if os.path.getsize(filename):
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
            buffer = f.read(16)
            x = cipher.decrypt(buffer)
            os.write(1,x)        
            while len(buffer) > 0:
                buffer = f.read(512);
                x = cipher.decrypt(buffer)
                os.write(1,x)       
    else:
        print("Não vai dar não champ")
decodeAES(sys.argv[1])