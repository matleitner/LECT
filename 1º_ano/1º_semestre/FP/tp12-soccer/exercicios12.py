import sys 


RANKING, NOME, PAIS, SCORE,SUBIDA, SCOREBEFORE, UPDOWN = 0,1,2,3,4,5,6 #posso usar isto ou, desempacotamento 

#for tup in lst:
#   RANKING, NOME, PAIS, SCORE,SUBIDA, SCOREBEFORE, UPDOWN = tup


def loadfile(filename):
    lista_total = []
    with open(filename,'r', encoding='utf-8') as f:
        f.readline() #le a primeira linha (skipa)
        for line in f:
            lst = line.strip().split(',')
            tup  = (int(lst[RANKING]),lst[NOME],lst[PAIS],int(lst[SCORE]), int(lst[SCOREBEFORE]),int(lst[UPDOWN]+lst[SUBIDA]))
            lista_total.append(tup)
    return lista_total


def returnclubesfile(lst,pais, f):
    print(f"Soccer Clubs from: {pais}\n", file =f)
    print("{:<20s}{:>7s}{:>7s}".format("NOME","RANKING","SCORE"), file =f) #s tring, d numero
    for tup in lst:
        if tup[PAIS] == pais:
            print("{:<20s}{:>7d}{:>7d}".format(tup[NOME],tup[RANKING],tup[SCORE]), file =f) #campos numericos sao auto ajustados a direita

def returnclubes(lst,pais,g):
    returnclubesfile(lst,pais, None) #None ou sys.strdout()


def savereturnclubes(lst, country,filename):
    with open(filename,'w',encoding='utf8') as f:
        returnclubes(lst, country, f)

def countryteams(lst):
    dic = {}
    for tup in lst:
        if tup[PAIS] not in dic:
            dic[tup[PAIS]] =[]
        dic[tup[PAIS]].append(tup[NOME])
    return dic


def mediumRank(lst):
    dic = countryteams(lst)
    s=0
    #print(dic)
    #for l in dic:
    #        s+=
     #       print(f"A média de {i} é: {s/len(i)}")
        

def showclubstats(clube,lst):

    for tup in lst:
        if tup[NOME] == clube:
            print(f'O clube, {clube}, tem as seguintes características:', end=' ')
            for i in range(6):
                if i==1:
                    pass
                else:
                    if i != 5:
                        print(tup[i], end=', ')
                    else: 
                        print(tup[i])
def main():
    lst = loadfile('Soccer_Football_Clubs_Ranking.csv')
    #returnclubes(lst,'Portugal')
    clubada = input('Nome clube:')
    returnclubesfile(lst, clubada, None)
    # showclubstats(clubada,lst)
    # savereturnclubes(lst, "Spain",'spain.txt')
    #print(lst)
    # for i in lst:
    #     if "München" in i[NOME]:
    #         print(i[NOME])
    #mediumRank(lst)
if __name__ == '__main__':
    main()
 