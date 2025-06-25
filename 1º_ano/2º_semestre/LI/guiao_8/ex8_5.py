from struct import pack
from math import sin, pi
import wave

def main(fname):
    rate = 44100
    wv = wave.open(fname, "w")
    wv.setparams((1,2,rate,0,"NONE", "not compressed"))

    amplitude = 9000
    data = []
    freq_a = 440
    freq_b = 880
    duration = 2 # em segundos  

    for i in range(0,rate):
        data.append(amplitude*sin(2*pi*freq_a*i/rate)+
                    amplitude*sin(2*pi*freq_b*i/rate))

    #Gerar (pack) a informacao no formato correto (16bits)
    wvData = []
    for v in data:
        wvData += pack("h", int(v))
    
    wv.writeframes(bytearray(wvData))
    wv.close()

main("wave_files/teste8_5.wav")
