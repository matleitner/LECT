from lxml import etree
import time;
import psutil


def main():
    tempo = time.time()
    with open("pcStats.xml", "w", encoding="utf-8") as f:
        root = etree.Element("stats")
        for i in range(60):
            value = etree.SubElement(root, "value")
            value.set("time",str(int(time.time()-tempo)))
            cpu = etree.SubElement(value, "cpu")
            cpu.text = str((psutil.cpu_percent(interval = 1))) 
            octetos =(etree.SubElement(value, "octetos"))
            octetos.text =str( psutil.net_io_counters()[0])
            # time.sleep(1)
        f.write(etree.tostring(root, xml_declaration = True, encoding= "utf-8", pretty_print=True).decode("utf-8"))
main()
