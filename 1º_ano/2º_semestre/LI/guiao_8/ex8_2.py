import pyaudio 
import wave

player = pyaudio.PyAudio()
wf = wave.open(("wave_files/piano.wav"), "rb")

sample_width = wf.getsampwidth() 
nchannels = wf.getnchannels()
fname_rate = wf.getframerate()

stream = player.open(format = player.get_format_from_width(sample_width), channels = nchannels, rate  = fname_rate, output= True)

while True: 
    data = wf.readframes(1024)
    if not data:
        break
    stream.write(data)

stream.close()
player.terminate()