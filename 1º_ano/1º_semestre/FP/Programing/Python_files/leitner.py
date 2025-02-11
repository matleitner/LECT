def team_maker():
    teams = []
    jogos= []
    equipa = "oaoaosao"
    while equipa != "":
        equipa = input("Quais Equipas jogam?")
        if equipa != "":
            teams.append(equipa)
            for i in teams:
                for j in teams:
                    if i != j:
                        match = (i,j)
                        jogos.append(match)
    
    return jogos

ola = team_maker()
print(ola)
