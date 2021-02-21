import os
import numpy as np


def convert_to_grid(logical_position):
    board_size = int(os.environ['BOARD_SIZE'])
    logical_position = np.array(logical_position, dtype=int)
    return (board_size/3)*logical_position + board_size/6

def convert_to_logical(grid_position):
    board_size = int(os.environ['BOARD_SIZE'])
    grid_position = np.array(grid_position)
    return np.array(grid_position//(board_size/3), dtype=int)

def check_cell_empty(board_status, logical_position):
    if board_status[logical_position[0]][logical_position[1]] != 0:
        return False
    else:
        return True

def check_board_winner(board_status, player):
    if player == 'X':
        player = -1
    else:
        player = 1
    #Chequear 3 en linea
    for i in range(3):
        if board_status[i][0] == board_status[i][1] == board_status[i][2] == player:
            return True
        if board_status[0][i] == board_status[1][i] == board_status[2][i] == player:
            return True
    #Chequear diagonales
    if board_status[0][0] == board_status[1][1] == board_status[2][2] == player:
        return True
    if board_status[0][2] == board_status[1][1] == board_status[2][0] == player:
        return True
    return False