import turtle
import math

screen = turtle.Screen()
screen.bgcolor("white")

pen = turtle.Turtle()
pen.speed(3)
pen.width(2)

# ⭐ STAR
pen.penup()
pen.goto(-300, 150)
pen.pendown()
pen.color("gold")
for _ in range(5):
    pen.forward(100)
    pen.right(144)

# ❤️ HEART
pen.penup()
pen.goto(-50, 100)
pen.pendown()
pen.color("red")
pen.begin_fill()
pen.left(50)
pen.forward(80)
pen.circle(30, 200)
pen.right(140)
pen.circle(30, 200)
pen.forward(80)
pen.end_fill()
pen.setheading(0)

# 🌹 ROSE (spiral flower)
pen.penup()
pen.goto(200, 120)
pen.pendown()
pen.color("darkred")
for i in range(100):
    pen.circle(i * 0.6, 60)
    pen.left(20)

# 🦋 BUTTERFLY
pen.penup()
pen.goto(0, -200)
pen.pendown()
pen.color("purple")

def wing():
    for i in range(40):
        pen.forward(2)
        pen.left(2)

pen.begin_fill()
wing()
pen.left(120)
wing()
pen.left(120)
wing()
pen.end_fill()

# Body
pen.penup()
pen.goto(0, -200)
pen.setheading(90)
pen.pendown()
pen.color("black")
pen.forward(80)

pen.hideturtle()
turtle.done()
