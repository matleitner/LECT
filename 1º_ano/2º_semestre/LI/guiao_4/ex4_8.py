from lxml import etree
import csv 
import time
import psutil
def main():

    xml = etree.parse("conf.xml")
    root = xml.getroot()
    monitor_cpu = root.findall("./monitor/cpu")[0].attrib["active"]
    monitor_ram = root.findall("./monitor/ram")[0].attrib["active"]
    monitor_network = root.findall("./monitor/network")[0].attrib["active"]
    (interval) = root.findall("./interval")[0].text
    file_type = root.findall("./output/csv")[0].attrib["active"]
    sep = root.findall("./output/csv")[0].attrib["separator"]
    
    interval = int (interval)
    fout = open("pcbitsStats.csv", "w")
    
    fieldNames = ["time","numero_octetos"]
    if monitor_cpu:
        fieldNames.append("processador(%)")
        

    writer = csv.DictWriter(fout,fieldnames =  fieldNames, delimiter = sep)
    writer.writeheader()
    if monitor_cpu:
        for i in range(0,interval+1):
            writer.writerow({"time": time.time(), "numero_octetos" : psutil.net_io_counters(), "processador(%)" : psutil.cpu_percent(1)} )
    else:
        for i in range(0,interval+1):
            writer.writerow({"time": time.time(), "numero_octetos" : psutil.net_io_counters()} )
            
    fout.close()  
main()