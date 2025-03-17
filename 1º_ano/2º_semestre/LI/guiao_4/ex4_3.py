import time
import psutil
import csv
import random
# print(time.time())
# print(time.time())
# print(psutil.cpu_percent(interval=2))
# print(psutil.net_io_counters())
def main():
    fout = open("pcStats.csv", "w")
    writer = csv.DictWriter(fout, fieldnames=["time", "numero_octetos", "processador(%)"])
    writer.writeheader()
    for i in range(0,61):
        writer.writerow({"time": time.time(), "numero_octetos" : psutil.net_io_counters(), "processador(%)" : psutil.cpu_percent(interval=1)} )
    fout.close()
main()