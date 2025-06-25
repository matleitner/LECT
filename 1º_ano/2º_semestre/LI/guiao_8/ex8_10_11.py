import wave
import struct
import sys
from struct import pack
import math
def copy(data):
    output = []
    for index,value in enumerate(data):
        output.append(value)
    return output
#ex11
def normalize(data):
    valor_max_abs = max(abs(min(data)),abs(max(data)))
    fator = 32767/valor_max_abs
    new_data = [d for i,d in enumerate(data)]
    return new_data

#ex10
def volume(data, fator_volume):
    new_data = []
    for i,d in enumerate(data):
        new_data.append(int(d* fator_volume))
    return new_data;

def main(argv):
    stream = wave.open("wave_files/"+argv[1], "rb")
    sample_rate = stream.getframerate()
    num_frames = stream.getnframes()
    raw_data = stream.readframes( num_frames )
    stream.close()
    data = struct.unpack("%dh" % num_frames, raw_data) # "B" para ficheiros 8bits
    # Aplica efeito sobre data, para output_data
    i = 2
    output_data = []
    while i < len(argv):
        if argv[i] == "copy":
            output_data = copy(data)
        elif argv[i] == "volume":
            output_data = volume(data, float(argv[i+1]))
        elif argv[i] == "normalize":
            output_data = normalize(data)        
        '''
        elif argv[i] == "foo":
            param = int(argv[i+1])
            output_data = foo(data, param)
            i += 1
        
        '''
        #elif ... Outros filtros
        i += 1
    wvData = b""
    for v in output_data:
        wvData += pack("h", int(v))
    stream = wave.open("out-8_11"+argv[1], "wb")
    stream.setnchannels(1)
    stream.setsampwidth(2)
    stream.setframerate(sample_rate)
    stream.setnframes(len(wvData))
    stream.writeframes(bytearray(wvData))
    stream.close()
if len(sys.argv) < 3:
    print("Usage: %s wave-file filter1 <params> filter2 <params> ..." % sys.argv[0])
else:
    main(sys.argv)
