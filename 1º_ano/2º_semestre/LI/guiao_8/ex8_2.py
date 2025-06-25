import wave
wf = wave.open(("wave_files/piano.wav"), "rb")

sample_width = wf.getsampwidth() 
nchannels = wf.getnchannels()
fname_rate = wf.getframerate()

print(wf.getparams())
wf.close()