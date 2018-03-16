//
//  Tile.cpp
//  Chess
//
//  Created by Andreas Aurlien on 16.03.2018.
//  Copyright © 2018 Andreas Aurlien. All rights reserved.
//

#include "Tile.hpp"

Tile::Tile(bool is_ocupied, Piece* piece) : is_ocupied(is_ocupied), piece(piece)
{
}


Tile::Tile() : is_ocupied(false), piece(nullptr)
{
}


Piece* Tile::get_piece() const
{
    return piece;
}

void Tile::set_piece(Piece* piece)
{
    this->piece = piece;
    is_ocupied = true;
}

/*
Tile::~Tile()
{
    if (piece != nullptr)
    {
        delete piece;
    }
}*/
