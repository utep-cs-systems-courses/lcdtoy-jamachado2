# lcdLib from Project 3: LCD Game
## Introduction

How it works:
Our button one will draw a square shape with a sound once is pressed.
Our second button will draw a custom shape with a different sound.
Our third button will draw a square with dotted traiangles and a diamon in the
center
Our four button will draw a "mini-ship"

By typing make load you will be able to run the code and make clean will
delete all unecessary files.

lcdLib provides primitives for a pixel, customShape, clearing the screen and a 8x12 font. 

switches.c is where we activate the switches to have control over them

buzzer.c give us access to different sounds

lcddraw.c is a file where we create all the methods to draw our shapes or
custom figures.

p1_interrupt_handler is where we control our switches once they are press they
will draw a different shape

shapmotion.c is a file where I tried to create a layer for my custome figure
to move (this file is incomplete)

wdt_handler.s is a file to control interrupts, framesize. (incomplete file)

