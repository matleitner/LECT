import wave 


def main():
    wf = wave.open( "wave_files/piano.wav" , "rb")
    print(wf.getparams())
    
    
    #print("Numero de Samples:", wf.getsampwidth())
    #print("Frames:", wf.getnframes())
    #print("Canais:", wf.getnchannels())
    #print("Freq amostragem:", wf.getframerate())
    wf.close()

main()