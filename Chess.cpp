//
//  Chess.cpp
//  Chess
//
//  Created by Andreas Aurlien on 15.03.2018.
//  Copyright © 2018 Andreas Aurlien. All rights reserved.
//

#include "Chess.hpp"

Chess::Chess()
{
    for (int row = 0; row < 8; row++)
    {
        std::vector<Tile> tile_row;
        
        for (int col = 0; col < 8; col++)
        {

            /*if (has_start_piece(row))
            {
                Piece temp_piece = get_start_piece(row, col);
                Tile temp_tile(true, &temp_piece);
            }
            else */
            {
                tile_row.push_back(Tile{false, nullptr});
            }
        }

        board.push_back(tile_row);
    }
}

Piece Chess::get_start_piece(int row, int col)
{
    bool white_start_row = (row == 0 || row == 1);
    bool black_start_row = (row == 6 || row == 7);
    if(!(white_start_row || black_start_row))
    {
        printf("It can´n be a start piece in this position");
        assert(!(white_start_row || black_start_row));
    }
    
    bool pawn = (row == 1 || row == 6), rook = (col == 0 || col == 7), knight = (col == 1 || col == 6),
        bishop = (col == 2 || col == 5), queen = (col == 3), king = (col == 4);
    
    int color = black_start_row; // 1 = black, 0 = white
    
    // if (pawn) return Pawn(color);
    // if (rook) return Rook(color);
    // if (knight) return Knight(color);
    // if (bishop) return Bishop(color);
    // if (queen) return Queen(color);
    // if (king) return King(color);
}

bool Chess::has_start_piece(int row)
{
    if (row == 0 || row == 1 || row == 6 || row == 7)
        return true;
    
    else return false;
}
