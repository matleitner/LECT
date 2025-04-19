import socket

def main():
    udp_s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    udp_s.bind(("127.0.0.1", 1234))
    while True:
        b_data, addr = udp_s.recvfrom(4096); 
        udp_s.sendto(b_data.upper(), addr);
        if b_data== "":
            break;

    udp_s.close();


main();