def genFibonacci(n):
    listaA = [0,1]
    z =0
    if n>2:
        while len(listaA)<n:
            x = listaA[z]+listaA[z+1]
            listaA.append(x)
            x=0
            z+=1
        return listaA
    else:
        return listaA
print(genFibonacci(7))
#O martim é lindo, e maravilhoso lixei me com L0