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
// #include <vector>
#include <array>
#include <assert.h>
#include <iostream>

#include "Piece.hpp"
#include "Tile.hpp"
#include "Unique_ptr.hpp"


class Chess
{
private:
    std::array<std::array<std::unique_ptr<Piece>, 8>, 8> board;
public:
    Chess();
    bool has_start_piece(int row) const;
    void list_all_pieces() const;
    
    bool is_piece(int row, int col, Color color, Chess_piece type) const;
    bool is_piece_nullptr(int row, int col) const;
    
    // std::unique_ptr<Piece>& get_pointer(int row, int col) const;
    // std::unique_ptr<Piece> get_start_piece(int row, int col) const;
    
    
};

#endif /* Chess_hpp */
