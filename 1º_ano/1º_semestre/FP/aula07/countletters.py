from unidecode import unidecode
import sys


filename = sys.argv[1] #inserir no 2º argumento o nome do ficheiro para ler 



char = {}
with open(filename,'r', encoding="utf8") as f:
    for line in f:
        for c in line:
            if c.isalpha(): #verifica se é uma letra
                c=unidecode(c.lower()) #mete tudo a lowercase
                if c in char:
                    char[c]+=1        #add um a imagem da letra
                else:
                    char[c]=1   #cria um spot para letra


def Getvalue(item):



    return item[1]


char = dict(sorted(char.items(), key = Getvalue, reverse = True))
for key,value in char.items():
    print(key,' ',value)



