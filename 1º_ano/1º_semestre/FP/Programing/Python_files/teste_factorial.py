def fatorial(num):
    fatorial = 1
    
    for i in range(1,num+1):
        fatorial*=i
    return fatorial


    


num = int(input('Insira um número inteiro:\n'))
print(f'{num}!=', end='')
for i in range(1,num+1):
    if i == num:
        print(i,end='')
    else:
        print(i,end='x')
print(f'={fatorial(num)}')