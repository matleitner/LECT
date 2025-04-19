import os
import random
from Cryptodome.Cipher import AES

key = os.urandom(16) # random key with 16 bytes
cipher = AES.new(key, AES.MODE_ECB)
while True:
    number = int (input("Insira um numero "))
    if number == 0:
        break
    data = cipher.encrypt(bytes("%16d" % (number), "utf8"))
    print(data)
    value = int(str(cipher.decrypt(data), "utf8"))
    print(value)