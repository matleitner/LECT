from struct import pack
from math import sin, pi
import wave

def main(fname):
    rate = 44100
    wv = wave.open(fname, "w")
    wv.setparams((1,2,rate,0,"NONE", "not compressed"))

    amplitude = 9000
    data = []
    freq = 1000
    duration = 4 # em segundos  

    for i in range(0,rate*duration):
        data.append(amplitude*sin(2*pi*freq*i/rate))

    #Gerar (pack) a informacao no formato correto (16bits)
    wvData = []
    for v in data:
        wvData += pack("h", int(v))
    
    wv.writeframes(bytearray(wvData))
    wv.close()

main("wave_files/teste8_4.wav")
