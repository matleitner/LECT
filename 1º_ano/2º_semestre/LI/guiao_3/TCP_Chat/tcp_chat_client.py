import socket
def main():
    tcp_c = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # tcp_c.bind(("127.0.0.1", 0))
    tcp_c.connect(("127.0.0.1", 1234)) # Ligar ao servidor
    while True:
        b_data = tcp_c.recv(4096)
        str_data = b_data.decode("utf-8")
        print("%s" % str_data)
        str_data = input(">>> ")
        if not str_data:
            break 
        b_data = str_data.encode("utf-8")
        tcp_c.send(b_data)
        # ---
        
    tcp_c.close()
main()