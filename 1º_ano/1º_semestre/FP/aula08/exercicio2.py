surname = {}
with open('names.txt','r') as f:
    f.readline()
    for line in f:
        nomes = line.split(' ')
        primeiro_nome = nomes[0]
        ultimo_nome = nomes[-1]
        if ultimo_nome in surname:
            surname[ultimo_nome] = set()
        surname[ultimo_nome].add(primeiro_nome)

for k,i in surname.items():
    print(k,' : ',i )