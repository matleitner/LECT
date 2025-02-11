jornada = input("Jornada?\t")
contador = 1

lst_guess = []
while not 0<int(jornada)<14:
    print("Jornada inválida!")
    jornada = input("Jornada?\t")


with open("Jornadas.csv") as f:
    for line in f:
        JORNADA, ANFITRIA, VISITANTE= line.strip().split(",")
        
        if JORNADA == jornada:
            print("{} {} vs {}".format(contador,ANFITRIA,VISITANTE),end="")
            guess = input("")
            while guess not in ["1", "2" , "X"]:
                guess = input("adsad")
            lst_guess.append(guess)
            contador += 1
    contador = 0 



with open("jornadas13.csv","w",encoding="UTF-8") as f:
        for i in lst_guess:
            contador +=1
            f.write(f"{contador}, {i}\n")