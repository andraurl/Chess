//
//  Tile.hpp
//  Chess
//
//  Created by Andreas Aurlien on 16.03.2018.
//  Copyright © 2018 Andreas Aurlien. All rights reserved.
//

#ifndef Tile_hpp
#define Tile_hpp

#include <stdio.h>
#include "Piece.hpp"


class Tile
{
private:
    bool is_ocupied;
    Piece* piece;
    
public:
    Tile();
    Tile(bool is_ocupied, Piece* piece);
    ~Tile();
    Piece* get_piece() const;
    void set_piece(Piece* piece);
};



#endif /* Tile_hpp */

