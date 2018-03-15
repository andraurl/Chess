//
//  Chess.hpp
//  Chess
//
//  Created by Andreas Aurlien on 15.03.2018.
//  Copyright © 2018 Andreas Aurlien. All rights reserved.
//

#ifndef Chess_hpp
#define Chess_hpp

#include <stdio.h>
#include <vector>
#include <assert.h>

#include "Piece.hpp"


struct Tile
{
    bool is_ocupied;
    Piece* piece;
    Tile(bool is_ocupied, Piece* piece)
    {
        this->is_ocupied = is_ocupied;
        this->piece = piece;
    }
};


class Chess
{
private:
    std::vector<std::vector<Tile>> board;
public:
    Chess();
    bool has_start_piece(int row);
    Piece get_start_piece(int row, int col);
    
};

#endif /* Chess_hpp */
