import socket 

def main():
    udp_s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
    udp_s.bind(("127.0.0.1", 1234))
    print("Servidor Ligado...")
    addr_list = []

    while True:
        b_data, adress = udp_s.recvfrom(4096)
        if not adress in addr_list:
            addr_list.append(adress)
            mesg = ("Estão: " +str(len(addr_list)) +" online!").encode("utf-8") ;
            b_data = mesg + b_data
        
        print(b_data.decode("utf-8"))
        
        for dst_addr in addr_list:
            if adress!= dst_addr:
                udp_s.sendto(b_data, dst_addr)
            else:
                udp_s.sendto(("Espere por uma resposta...").encode(), dst_addr)


        if "vou desligar" in b_data.decode():
            print(adress[0]+ " disconectou..")
            addr_list.remove(adress)
            break;
        
    udp_s.close()

main()