class Constant:
    def __init__(self, num ):
        self.num = num
        
    def __str__(self):
        return str(self.num)


class Soma:
    def __init__(self, arg1, arg2):
        self.arg1 = arg1
        self.arg2 = arg2
        
    def __str__(self):
        return str(self.arg1) + "+" + str(self.arg2)

class Multiplication:
    def __init__(self, arg1, arg2):
        self.arg1 = arg1
        self.arg2 = arg2

    def __str__(self):
        return str(self.arg1)+ "*" + str(self.arg2)

class Variable:
    def __init__(self, var):
        self.var = var;

    def __str__(self):
        return str(self.var)



print(Soma(Constant(23), Multiplication(Constant(1), Variable("x"))))
