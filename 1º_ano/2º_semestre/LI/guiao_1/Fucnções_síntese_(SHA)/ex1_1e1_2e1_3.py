import hashlib
import sys
import os.path

# Programa que calcula e apresenta a sintese de ficheiros SHA-1 e SHA-256 ( basta trocar a linha 8 de sha1 para sha256)

def calcular_sha1(filename):
        sha1 = hashlib.sha1();
        with open(filename, "rb") as f:
            buffer = f.read(512);
            sha1.update(buffer)
        
            while len(buffer)> 0:
                buffer = f.read(512)
                sha1.update(buffer)
                
        return sha1.hexdigest();

if len (sys.argv) < 2 :
    print ("Usage: python3 %s filename" % (sys.argv[0]))
    sys.exit (1)
fname = sys.argv[1] # verify if it is a file

if not os.path.exists(fname) or os.path.isdir(fname) or not os.path.isfile(fname):
    print(fname + " is not a file", file=sys.stderr)
    sys.exit (2)

hash_sha1 = calcular_sha1(fname)

print(f"SHA-1 {fname}: {hash_sha1}")
