listagem = {1:"Registar chamada",2:"Ler fichero",3:"Listar",4:"Fatura",5:"Terminar"}


for i in listagem:
    print(f"{i}) {listagem[i]}")
op = 0 
while op not in listagem:
    op = int(input("Opção?\n"))

def valid_phone_num(num):
    return num.isdigit() and 3<=len(num)<=9 or num[0] == "+" and num[1:].isdigit() and 11>=len(num[1:])>=3

def registar_chamadas(num):
    num = input("Telefone origem? ")
    while not valid_phone_num(num): 
        num = input("Telefone origem? ")
    num_dest = input("Telefone destino?")

    while not valid_phone_num(num_dest) or num_dest == num:
        num_dest = input("Telefone destino?")
    tempo = input("Duração (s)?")
    while int(tempo)<=0:
        tempo = input("Duração (s)?")
    print("Numero valido")

def ler_ficheiro(f):
    dct = {}

    with open(f) as fname:
        for line in fname:
            line = tuple(line.strip().split())
            if line[0] not in dct:
                dct[line[0]]=[(line[1],line[2])]
            else:
                dct[line[0]].append((line[1],line[2]))

        return(dct)

def listar_clientes(f):
        array = set()       
        for i in ler_ficheiro(f):
            array.add(i)
        array = sorted(array)
        return array

def fatura(num, dct):
    
    if num in dct:
        print(f"Fatura do cliente {num}")
        print(f"{"Destino":<15}{"Duração":^13}{"Custo":>12}")
        total = 0
        for i in dct[num]:
            custo = 0
            if i[0][0]=="2":
                custo = int(i[1])*0.02/60
            elif i[0][0] == "+":
                custo = int(i[1])*0.8/60
            elif i[0][0] == i[1]:
                custo = int(i[1])*0.04/60
            else:
                custo = int(i[1])*0.1/60
            print("{:<15} {:^10s} {:>15.2f}".format(i[0],i[1],custo))
            total+=custo
            # print(total)
    print(f"{"Total\t":>32s}{total:>.2f}")
ficheiro = input("Insira o nome do ficheiro:")
match op:   
    case 1:
        registar_chamadas()    
    case 2:    
        print(ler_ficheiro(ficheiro))
    case 3:
        for i in listar_clientes(ficheiro):
            print(i,end=" ")
    case 4:  
        num = input("Cliente?")   
        fatura(num,ler_ficheiro(ficheiro))

    case _:
        op = input("numero invalido")