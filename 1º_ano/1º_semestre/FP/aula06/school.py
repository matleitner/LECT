# Complete o programa!

# a)
def loadFile(fname, lst):
    piriquito = True
    with open(fname, 'r') as file:
        for line in file:
            if piriquito:
                piriquito = not piriquito
            else:
                separado = line.split("\t")
                número= int(separado[0]) 
                nome= separado[1]
                nota1 = float(separado[5])
                nota2=  float(separado[6])
                nota3= float(separado[7])
                tuplinha = (número, nome, nota1, nota2, nota3)

                lst.append(tuplinha)   
    return lst         
# b) Crie a função notaFinal aqui...
...
def notaFinal(reg):
    return (reg[-3]+reg[-2]+reg[-1])/3.0

# c) Crie a função printPauta aqui...
...
def printPauta(lst):
    print("{:>s}\t{:^50s}\t{:>s}".format("NUMERO","NOME","NOTA"))
    for reg in lst:
        print("{:>d}\t{:^50s}\t{:>2.1f}".format(reg[0],reg[1],notaFinal(reg)))
    
    
# d)
def main():
    lst = []
    # ler os ficheiros
    loadFile("school1.csv", lst)
    loadFile("school2.csv", lst)
    loadFile("school3.csv", lst)
    
    # ordenar a lista
    lst.sort()
    
    # mostrar a pauta
    printPauta(lst)


# Call main function
if __name__ == "__main__":
    main()


