# Complete the code to make the HiLo game.

import random

def playHiLo():
    # Pick a random number between 1 and 100, inclusive
    secret = random.randrange(1, 101)
    guesses = 0
    contador = 0
    print("I picked a number between 1 and 100. Can you guess it?")
    # put your code here
    while guesses != secret:
        print("Can you guess it, again?")
        guesses = int(input())
        contador+=1
        if guesses>secret:
            print("High")
        elif guesses<secret:
            print("Low")
        else:
            print("ACERTASTE és o MAIOR. Tentativas: {}".format(contador))


playHiLo()

