roads = {("Coimbra","Viseu"):91,("Santiago","Seia"):1,("Seia","Viseu"):21}

def distance(dct: dict, c1,c2):
    if (c1,c2) in dct.keys():
        return f"A distância entre {c1} e {c2}", dct[(c1,c2)]
    if (c2,c1) in dct.keys(): 
        return f"A distância entre {c1} e {c2}", dct[(c2,c1)]
    else:
        return "Não exite primo"


print(distance(roads,"Seia","Coimbra"))