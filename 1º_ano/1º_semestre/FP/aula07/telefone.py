# Complete este programa como pedido no guião da aula.

def listContacts(dic):
    """Print the contents of the dictionary as a table, one item per row."""
    print("{:>12s} : {} : {:>20s}".format("Numero", "Nome",'Morada'))
    for num in dic:
        print("{:>12s} : {} : {:30s}".format(num, dic[num][0],dic[num][1]))

def filterPartName(contacts, partName):
    """Returns a new dict with the contacts whose names contain partName."""
    ...


def menu():
    """Shows the menu and gets user option."""
    print()
    print("(L)istar contactos")
    print("(A)dicionar contacto")
    print("(R)emover contacto")
    print('Procurar (H)abitaçao')
    print("Procurar (N)úmero")
    print("Procurar (P)arte do nome")
    print("(T)erminar")
    op = input("opção? ").upper()   # converts to uppercase...
    return op

def searchNumber(contacts):
    num_search = input("Numero a procurar:")
    print(contacts.get(num_search,num_search))
        
def searchName(contacts):
    nome = input('nome parcial:')
    
    match={}
    for key, valor in contacts.items():
        if nome in valor:
           match[key]=valor 
    listContacts(match)




def addContact(contactos):
    num_contato= input("Insira um numero para guardar:")
    nome_contato = input('Insira o nome do contato:')
    contactos[num_contato]=nome_contato

def removeContact(contactos):
    num_contato= input("Insira um numero para retirar:")
    contactos.pop(num_contato)
def main():
    """This is the main function containing the main loop."""

    # The list of contacts (it's actually a dictionary!):
    contactos = {"234370200": ("Universidade de Aveiro",'Aveiro'),
        "727392822": ("Cristiano Aveiro",'Porto'),
        "387719992": ("Maria Matos",'Seia'),
        "887555987": ("Marta Maia",'Lisboa'),
        "876111333": ("Carlos Martins",'Pimba'),
        "433162999": ("Ana Bacalhau",'Katchau')
        }

    op = ""
    while op != "T":
        op = menu()
        if op == "T":
            print("Fim")
        elif op == "L":
            print("Contactos:")
            listContacts(contactos)
        elif op == 'A':
            addContact(contactos)
        elif op == 'N':
            searchNumber(contactos)
        elif op == 'P':
            searchName(contactos)
        
        else:
            removeContact(contactos)
            print("Não implementado!")
    

# O programa começa aqui
main()

