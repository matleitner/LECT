from socket import *

tcp_s = socket(AF_INET, SOCK_STREAM)

tcp_s.bind(("127.0.0.1", 1234))
tcp_s.listen(1)
client_s, client_addr = tcp_s.accept()
while True:
    data = client_s.recv(4096)
    
    if not data:
        break
    
    tcp_s.send(data.upper())


client_s.close()
tcp_s.close()
