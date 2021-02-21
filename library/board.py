import os
import tkinter
import numpy as np
from . import drawings
from . import logics


class GameBoard():

    def __init__(self):
        self.size = int(os.environ['BOARD_SIZE'])
        self.window = tkinter.Tk()
        self.window.title('TaTeTi')
        self.canvas = tkinter.Canvas(self.window, width=self.size, height=self.size)
        self.canvas.pack()
        self.window.bind('<Button-1>', self.on_click)
        self.board_status = np.zeros(shape=(3, 3))

    def on_click(self, event):
        position = [event.x, event.y]
        position = logics.convert_to_grid(position)

    def start_board(self):
        drawings.draw_empty_board(self.canvas, self.size)

    def is_winner(self, player):
        return logics.check_board_winner(self.board_status, player)
        
    def mainloop(self):
        self.window.mainloop()
