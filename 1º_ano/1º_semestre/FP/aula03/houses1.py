"""
This program uses the module turtle to draw "turtle graphics".

You may check the official tutorial on turtle graphics:
https://docs.python.org/3/library/turtle.html#use-object-oriented-turtle-graphics

Or read the Turtles chapter in the Python for everybody book:
https://runestone.academy/ns/books/published/py4e-fp-ua-pt/turtles/toctree.html

For a summary of the available methods:
https://runestone.academy/ns/books/published/py4e-fp-ua-pt/turtles/summary.html#summary-of-turtle-methods
"""

import turtle               # allows us to use the turtles library


# Drawing functions on this program assume that the pen is up.

def rect(t, x, y, width, height):
    """Make turtle t draw a rectangle with the given width and height."""
    assert not t.isdown(), "Pen should be up!"
    t.goto(x, y)
    t.down()
    t.goto(x+width, y)
    t.goto(x+width, y+height)
    t.goto(x, y+height)
    t.goto(x, y)
    t.up()

def triang(t, x, y, width, height):
    """Draw filled isosceles triangle."""
    t.goto(x, y)
    t.down()
    t.begin_fill()
    t.goto(x+0.5*width, y+height)
    t.goto(x+width, y)
    t.end_fill()
    t.up()

def house(t, x, y, width, height):
    rect(t, x, y, width, height)
    # Complete the function to draw a roof, a door and a window.
    ...
    

def main():
    print("This program opens a window with a graphical user interface.")
    print("Click buttons on the mouse to draw stuff.")

    screen = turtle.Screen()        # creates a graphics window
    t = turtle.Turtle()
    t.speed(0)  # no animation
    t.up()      # start with pen up

    w = 40
    h = 30

    # A local function that accesses variables in main!
    def doclick1(x, y):
        rect(t, x, y, w, h)

    # Tell the screen which function to call when mouse button 1 is clicked
    screen.onclick(doclick1, 1)

    # Add code to draw a house when button 3 is clicked...
    ...
        
    screen.mainloop()
    print("The window was closed. Bye!")


main()

