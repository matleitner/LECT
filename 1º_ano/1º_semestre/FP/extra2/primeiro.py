def menu():
    done = False
    while done == False:

        print('1) Registar chamada ')
        print('2) Ler ficheiro ')
        print('3) Listar clientes')
        print('4) Fatura')
        print('5) Terminar') 
        op = input('Opcão:')
        if op in ['1','2','3','4','5']:
            done = True
        else:
            print('Operação inválida')
    return op
def invalid(num):
    if num[0]=='+':
        if len(num)<4:
            return False
        else:
            num = num[1:]
    else:
        if len(num)<3:
            return False
    for i in num:
        if i.isdigit():
            print("miau")



def main():
    op = menu()

    match op:
        case '1':
            print('a')
        case '2':
            print('b')
        case '3':
            print('c')
        case '4':
            print('d')
        case '5':
            print('e')
    
if __name__ == "__main__":
    main()