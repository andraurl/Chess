//
//  Piece.cpp
//  Chess
//
//  Created by Andreas Aurlien on 15.03.2018.
//  Copyright © 2018 Andreas Aurlien. All rights reserved.
//

#include "Piece.hpp"

Piece::Piece(int color, Chess_piece type)
{
    this->color = color;
    this->type = type;
}

// /* TA VEKK DENNE FOR Å FÅ TILBAKE
King::King(int color) : Piece(color, KING)
{
    
}

Queen::Queen(int color) : Piece(color, QUEEN)
{
    
}


Rook::Rook(int color) : Piece(color, ROOK)
{
    
}


Bishop::Bishop(int color) : Piece(color, BISHOP)
{
    
}


Knight::Knight(int color) : Piece(color, KNIGHT)
{
    
}


Pawn::Pawn(int color) : Piece(color, PAWN)
{
    
}
// TA VEKK DENNE FOR Å FÅ TILBAKE */

