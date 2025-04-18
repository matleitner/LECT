import sys
import os
import hashlib
from Cryptodome.Cipher import ARC4 
def decrypt(filename):
    key = sys.argv[2]
    # print(key)
    if len(key)<5:
        chave_sintetizada = hashlib.sha256(key.encode()).digest()        
        key = chave_sintetizada[:256]
    elif len(key)>256:
        key = key[:256]
    # print(key)
    else:
        key = key.encode("utf-8")

    with open(filename, "rb") as f:
        nome= f.read()
        decipher = ARC4.new(key)
        # print()
        decrypthed = decipher.decrypt(nome)

        print(decrypthed.decode("utf-8"))

if __name__ == "__main__":
    decrypt(sys.argv[1])