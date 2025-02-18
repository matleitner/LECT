import hashlib
import sys
import os.path

def calcular_sha1(filename):
    with open(filename, "rb") as f:
        n=0
        buffer = f.read(512)
        h= hashlib.sha256()
        while len(buffer)>0:
            h.update(buffer)
            buffer= f.read(512)
            n+=1
    return h.hexdigest(), n
print(calcular_sha1("texto.txt"))