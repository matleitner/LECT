from socket import *

tcp_s = socket(AF_INET, SOCK_STREAM)

tcp_s.bind(("127.0.0.1",1234))
tcp_s.listen(5)
print("à espera..")
client_s, client_addr = tcp_s.accept()
print("conectado!")

while True:
    client_s.send("Insira a sua mensagem:\n>>>".de())
    data = client_s.recv(4096)
    
    if not data.split():
        print("Cliente desconectou.")

        
        print(data)
        
        break
    else:
        print(client_addr, " ", client_s)
        print( (data))
        print(data.decode())
        client_s.send(data.upper())

client_s.close()
tcp_s.close()
