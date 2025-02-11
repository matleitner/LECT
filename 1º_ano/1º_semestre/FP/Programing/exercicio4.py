def permutation(a):
    if len(a)<=1:
        return list(a)
    lst = []
    

    for i,char in enumerate(a):
        resto = a[:i]+a[i+1:]

        for perm in permutation(resto):
            lst.append(char + perm)
    return lst

print(permutation("abcd"))




def parseTime(s: str)-> int:
    tempo= s.split("h")
    if len(tempo) == 1:
        return int(tempo[0])
    if tempo[1]=="":
        return int(tempo[0])*60
    tempo = int(tempo[0])*60+int(tempo[1])
    return tempo

print(parseTime("5h"))
# print("1h".split("h"))