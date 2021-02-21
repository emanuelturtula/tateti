import os


def load():
    size = 600
    symbol_size = (size/3 - size/8)/2
    thickness = 50
    o_colour = '#0492CF'
    x_colour = '#EE4035'

    os.environ['BOARD_SIZE'] = str(size)
    os.environ['SYMBOL_SIZE'] = str(symbol_size)
    os.environ['THICKNESS'] = str(thickness)
    os.environ['O_COLOUR'] = o_colour
    os.environ['X_COLOUR'] = x_colour

