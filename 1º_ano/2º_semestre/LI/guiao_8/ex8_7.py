from struct import pack
from math import sin, pi
import wave

def main(fname):
    rate = 44100
    wv = wave.open(fname, "w")
    wv.setparams((1,2,rate,0,"NONE", "not compressed"))
    
    tons = {
        "1": (697,1029),  
        "2":(697,1336),
        "3":(697,1477),
        "4":(770,1209),
        "5":(770,1336),
        "6":(770,1477),
        "7":(852,1209),
        "8":(852,1336),
        "9":(852,1477),
        "0":(941,1336),        
        }
    number = input("Insira um numero: ")


    amplitude = 9000
    data = []
    
      
    for n in number:
        for i in range(0,int(rate* 0.40)):
            data.append(amplitude*sin(2*pi*tons[n][0]*i/rate)+
                        amplitude*sin(2*pi*tons[n][1]*i/rate))
        for i in range(0,int(rate *0.40)):
            data.append(0)

    #Gerar (pack) a informacao no formato correto (16bits)
    wvData = []
    for v in data:
        wvData += pack("h", int(v))
    
    wv.writeframes(bytearray(wvData))
    wv.close()

main("wave_files/teste8_7.wav")
