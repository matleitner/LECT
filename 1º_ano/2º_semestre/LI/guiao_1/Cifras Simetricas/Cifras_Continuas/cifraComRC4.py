
import sys
import os
import hashlib
from Cryptodome.Cipher import ARC4 


def abrir_file(filename):
    key = sys.argv[2]
    
    if len(key)<5:
        chave_sintetizada = hashlib.sha256(key.encode()).digest()        
        key = chave_sintetizada[:256]
    elif len(key)>256:
        key = key[:256].encode()
    
    
    with open(filename, "rb") as f:
        nome= f.read()
        # print()
        # print(len(nome), "antes")
        cipher = ARC4.new(key.encode("utf-8"))
        cryptogram = cipher.encrypt(nome)
        os.write(1,cryptogram) #Em Python os descritores dos ficheiros stdin, stdout e stderr são representados pelos números inteiros, respetivamente, 0, 1 e 2.
        # print(len(cryptogram), "depois")


        # decipher = ARC4.new(key.encode("utf-8"))
        # # print()
        # decrypthed = decipher.decrypt(cryptogram)

        # print(decrypthed.decode("utf-8"))

abrir_file(sys.argv[1])
#python3 cifraComRC4.py texto.txt chaveSecreta > chaveSecreta.txt
