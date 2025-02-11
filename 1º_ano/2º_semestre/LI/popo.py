import turtle
import random

puta = turtle.Turtle()
atuamae = turtle.Turtle()
johny = turtle.Turtle()
atchim = turtle.Turtle()


puta.shape("turtle")
puta.color("blue")
puta.penup()
puta.setpos(-100, 200)
#----------------------------------------------------
atuamae.shape("turtle")
atuamae.color("pink")
atuamae.penup()
atuamae.setpos(-100, 100)
#---------------------------------------------------
johny.shape("turtle")
johny.color("red")
johny.penup()
johny.setpos(-100, 0)
#------------------------------------------------------
atchim.shape("turtle")
atchim.color("green")
atchim.penup()
atchim.setpos(-100, -100)

turtle.penup()
turtle.setpos(300, 300)
turtle.pendown()
turtle.right(90)
turtle.forward(450)
turtle.penup()

while puta.xcor()<300 and atuamae.xcor()<300 and johny.xcor()<300 and atchim.xcor()<300:
    puta.forward(random.randint(1,10))
    atuamae.forward(random.randint(1,10))
    johny.forward(random.randint(1,10))
    atchim.forward(random.randint(1,10))

turtle.setpos(100, 300)
if puta.xcor()>=300:
    turtle.write("Ganhou a tartaruga puta")
elif atuamae.xcor()>=300:
    turtle.write("Ganhou a tartaruga atuamae")
elif johny.xcor()>=300:
    turtle.write("Ganhou a tartaruga johny")
else:
    turtle.write("Ganhou a tartaruga atchim")
    
turtle.exitonclick()