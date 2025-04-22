import requests
import time

t = time.time()
f = requests.get("http://www.ua.pt")
t = time.time()-t

print(t)

print(f.text)

#print(f.headers['Content-Type'])
#for header in f.headers:
 #   print(f"{header}")

#print(f.headers)

l = requests.get("http://www.kernel.org")

#print(l.headers)