def fibonacci(n):
    res = []
    if n < 0:
        return res 
    if n == 0:
        return [0]
    if n == 1:
        return [0,1]
    if n>1:
        res = [0,1]
        for i in range(n-1):
            res.append(res[-1]+res[-2])
        return res

def teste1():
    if fibonacci(0) == [0] and fibonacci(-1) == []:
        print("Teste OK")
    else:
        print("Teste Falhou")
print(fibonacci(10))
