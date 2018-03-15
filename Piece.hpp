//
//  Piece.hpp
//  Chess
//
//  Created by Andreas Aurlien on 15.03.2018.
//  Copyright © 2018 Andreas Aurlien. All rights reserved.
//

#ifndef Piece_hpp
#define Piece_hpp

#include <stdio.h>

enum Chess_piece
{
    KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN
};



class Piece
{
private:
    int color;
    Chess_piece type;
public:
    Piece(int color, Chess_piece type);
    // virtual void leagal_move() = 0;
    
};

// /* TA VEKK DENNE FOR Å FÅ TILBAKE

class King : public Piece
{
private:
public:
    King(int color);
    void leagal_move();
    
};


class Queen : public Piece
{
private:
public:
    Queen(int color);
    void leagal_move();
    
};


class Rook : public Piece
{
private:
public:
    Rook(int color);
    void leagal_move();
    
};

class Bishop : public Piece
{
private:
public:
    Bishop(int color);
    void leagal_move();
    
};

class Knight : public Piece
{
private:
public:
    Knight(int color);
    void leagal_move();
    
};

class Pawn : public Piece
{
private:
public:
    Pawn(int color);
    void leagal_move();
    
};
// */ TA VEKK DENNE FOR Å FÅ TILBAKE
#endif /* Piece_hpp */


