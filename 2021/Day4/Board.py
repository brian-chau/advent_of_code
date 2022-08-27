#!/usr/bin/python3.10

# Standard library
import numpy as np
import sys
from   typing import Final

# Project library
# N/A

# Constants
HORIZ_AXIS: Final[int] = 0
VERT_AXIS:  Final[int] = 1

class Board:
    def __init__( self, lines: list, board_size: int ):
        self.board_size = board_size
        self.board      = np.array( lines, dtype = int )
        self.selected   = np.zeros( ( board_size, board_size ), dtype=int )
        self.won        = False
        self.points     = 0

    def display( self ):
        print( self.board )

    def display_selected( self ):
        print( self.selected )

    def score( self, number: int ) -> ( int ):
        if not self.won:
            self.points = ( ( self.board * ( self.selected==0 ) ).sum() * number )
            self.won    = ( self.points > 0 )

        return self.points

    def select_number( self, number: int ):
        if number in self.board:
            indices = np.where( self.board == number )
            self.selected[ indices[ HORIZ_AXIS ], indices[ VERT_AXIS ] ] = 1

    def is_number_selected( self, number: int ) -> bool:
        return number in self.board

    def is_winner( self ) -> bool:
        return self.selected.all( axis=HORIZ_AXIS ).any() or self.selected.all( axis=VERT_AXIS ).any()
