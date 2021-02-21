import os
import numpy as np
from . import logics


def draw_empty_board(canvas, size):
    #Dibujar lineas verticales
    for i in range(2):
        canvas.create_line((i+1)*size/3, 0, (i+1)*size/3, size)

    #Dibujar lineas horizontales
    for i in range(2):
        canvas.create_line(0, (i+1)*size/3, size, (i+1)*size/3)

def draw_O(canvas, position):
    colour = os.environ['O_COLOUR']
    symbol_size = int(os.environ['SYMBOL_SIZE'])
    thickness = int(os.environ['THICKNESS'])
    #La posicion es lógica
    position = np.array(position)
    #Hay que convertirla en una posicion valida para la grilla
    position = logics.convert_to_grid(position)
    canvas.create_oval(position[0]-symbol_size, position[1]-symbol_size,
                        position[0]+symbol_size, position[1]+symbol_size, 
                        width=thickness, outline=colour)

def draw_X(canvas, position):
    colour = os.environ['X_COLOUR']
    symbol_size = int(os.environ['SYMBOL_SIZE'])
    thickness = int(os.environ['THICKNESS'])
    #La posicion es lógica
    position = np.array(position)
    #Hay que convertirla en una posicion valida para la grilla
    position = logics.convert_to_grid(position)
    canvas.create_line(position[0]-symbol_size, position[1]-symbol_size,
                        position[0]+symbol_size, position[1]+symbol_size, 
                        width=thickness, fill=colour)
    canvas.create_line(position[0]-symbol_size, position[1]+symbol_size,
                        position[0]+symbol_size, position[1]-symbol_size, 
                        width=thickness, fill=colour)