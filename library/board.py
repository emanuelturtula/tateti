import os
import tkinter
import numpy as np
from . import drawings
from . import logics


class GameBoard():

    def __init__(self, player):
        self.size = int(os.environ['BOARD_SIZE'])
        self.window = tkinter.Tk()
        self.window.title('TaTeTi')
        self.canvas = tkinter.Canvas(self.window, width=self.size, height=self.size)
        self.canvas.pack()
        self.window.bind('<Button-1>', self.on_click)
        self.board_status = np.zeros(shape=(3, 3))
        self.player = player
        self.turn = 'X'

    def on_click(self, event):
        grid_position = [event.x, event.y]
        logical_position = logics.convert_to_logical(grid_position)
        if (self.turn == 'X') and (self.player == 'X'):
            if self.is_cell_empty(logical_position):
                drawings.draw_X(self.canvas, logical_position)
                self.board_status[logical_position[0]][logical_position[1]] = -1
                self.turn = 'O'
            else:
                print("This cell is not empty!")
        elif (self.turn == 'O') and (self.player == 'O'):
            if self.is_cell_empty(logical_position):
                drawings.draw_O(self.canvas, logical_position)
                self.board_status[logical_position[0]][logical_position[1]] = 1
                self.turn = 'X'
            else:
                print("This cell is not empty!")
        else:
            print("It is not your turn")

    def start_board(self):
        drawings.draw_empty_board(self.canvas, self.size)

    def is_cell_empty(self, logical_position):
        return logics.check_cell_empty(self.board_status, logical_position)

    def is_winner(self, player):
        return logics.check_board_winner(self.board_status, player)

    def who_plays(self):
        return self.turn
        
    def mainloop(self):
        self.window.mainloop()
