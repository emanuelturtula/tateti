import settings
import library.board as board


def main():
    load_settings()
    game_board = board.GameBoard('X')
    game_board.start_board()
    game_board.mainloop()

def load_settings():
    settings.load()

main()