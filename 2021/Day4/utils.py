#!/usr/bin/python3.10

# Standard library
# N/A

# Project library
from Board import *

def read_file( filename: str, board_size: int ) -> ( list, list ):
    with open( filename ) as f:
        lines = f.readlines()

    selected_numbers = list( map( int, lines[0].split(',') ) )
    lines = [ line for line in lines[1:] if line.strip() != '' ]

    boards = []
    for i in range(0, len( lines ), board_size ):
        boards.append( Board( lines=[ list( map( int, line.strip().split() ) ) for line in lines[ i:i+board_size ] ], board_size=board_size ) )

    return selected_numbers, boards