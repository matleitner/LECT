import socket;

def main(port, nome):
    udp_client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    udp_client.bind(("127.0.0.1", port))
    server_adress = ("127.0.0.1", 1234)
    udp_client.sendto((nome+" is Online").encode(), server_adress)
    espera = False
    while True:
        b_mensagem, adress = udp_client.recvfrom(4096)
        mensagem_recebida= b_mensagem.decode("utf-8")
        
        if (mensagem_recebida == "Espere por uma resposta..."):
            espera = True;
        else: 
             espera = False;
        print(mensagem_recebida)
        if not espera:
            mensagem = input(nome+"(eu)-> ")
            udp_client.sendto((nome + ": "+ mensagem).encode("utf-8"), server_adress)
            if mensagem == "vou desligar":
                break
        
        
        
    
    udp_client.close()



port = input("Qual é a tua porta..")
nome = input("Insira o seu nome de utilizador: ")
main(int (port), nome)
