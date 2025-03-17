import csv
import sys
def main(argv):
    temp = []
    fich_csv = open(argv[1], "r")
    csv_reader = csv.reader(fich_csv, delimiter=",")
    fich_csv.readline()
    for row in csv_reader:
        temp.append(float(row[-1]))

    print(f"A média é:{ sum(temp)/len(temp): .2f}")
    print("O máximo é: ", max(temp))
    print("O mínimo é : ", min(temp))
    

    
    
    fich_csv.close()

main(sys.argv)
