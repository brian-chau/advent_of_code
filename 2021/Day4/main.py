#!/usr/bin/python3.10

# Standard library
from typing import Final

# Project library
from   Board import *
import utils

board_size: Final[int] = 5

if __name__ == '__main__':
    selected_numbers, boards = utils.read_file( filename='input.txt', board_size=board_size )

    winning_boards = []
    winning_indices = []
    for number in selected_numbers:
        for i, board in enumerate( boards ):
            board.select_number( number )
            if board.is_winner( ) and i not in winning_indices:
                winning_boards.append( ( i, board.score( number ) ) )
                winning_indices.append( i )

    print( f'First board: { winning_boards[ 0 ] }' )
    print( f'Last board:  { winning_boards[ -1 ] }' )