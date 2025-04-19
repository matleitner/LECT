from socket import *

tcp_s = socket(AF_INET, SOCK_STREAM)

tcp_s.bind(("127.0.0.1",1234))
tcp_s.listen()
print("à espera..")
client_s, client_addr = tcp_s.accept()
print("conectado!")

while True:
    client_s.send("\nInsira a sua mensagem:\n".encode())
    data = client_s.recv(4096)
    
    if not data or not data.decode().split():
        
        print("Cliente desconectou.")
        break


    else:
        print((data))
        print(data.decode())
        client_s.send(b"Resposta: "+data.upper()+ b"\n")

client_s.close()
tcp_s.close()
