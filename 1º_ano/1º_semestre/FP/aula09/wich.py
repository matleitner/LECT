import bisect



lst= []

comeca = input('insira as letras: ')

while not comeca.isalpha():
    comeca = input('insira as letras: ')
def endnewletter(comeca): 
    if comeca:
        last = comeca[-1]
        resto = comeca[:-1]
    if last != 'z':
        new_word = resto + chr(ord(last)+1)
    else: 
        
        new_word = comeca
    return new_word
new_word = endnewletter(comeca)


with open('wordlist.txt','r') as f:
    for line in f:
        lst.append(line.strip('\n'))

def diference(c,n):
    return bisect.bisect_left(lst,n)-bisect.bisect_left(lst,c)
    
    
while diference(comeca,new_word)==0:
    new_word = endnewletter(new_word)
    diference(comeca,new_word)

print(diference(comeca,new_word))

