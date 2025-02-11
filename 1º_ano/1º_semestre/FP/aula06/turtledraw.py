# Exercise 5 on "How to think like a computer scientist", ch. 11.

import turtle

def main():
    screen = turtle.Screen()
    t = turtle.Turtle()

    # Use t.up(), t.down() and t.goto(x, y)

    # Put your code here
    file = open("drawing.txt",'r')
    for line in file:
        if line == "UP\n":
            t.up()
        elif line == 'DOWN\n':
            t.down()
        else:
            pipiripipi = line.split(" ")
            x =int(pipiripipi[0])
            y = int(pipiripipi[1])
            t.goto(x,y)
    # Wait until window is closed
    screen.mainloop()


if __name__ == "__main__":
    main()

