# Alterar exercicio 3 


import time
import psutil
import json

def main():
    fout = open("pcStats.json", "w")
    data = []
    
    for i in range(0,61):
        data.append({"time": time.time(), "numero_octetos" : psutil.net_io_counters(), "processador(%)" : psutil.cpu_percent(interval=1)} )
    
    fout.write(json.dumps(data, indent=4))
    fout.close()
main()