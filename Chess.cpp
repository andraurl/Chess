//
//  Chess.cpp
//  Chess
//
//  Created by Andreas Aurlien on 15.03.2018.
//  Copyright © 2018 Andreas Aurlien. All rights reserved.
//

#include "Chess.hpp"

using namespace std;

Chess::Chess()
{
    // reset_maked_tiles();
    number_of_marked_tiles = 0;
    players_turn = Color::White;
    first_marked_piece = nullptr;
    second_marked_piece = nullptr;
    
    // PAWNS
    for (int i = 0; i < 8; i++)
    {
        board[1][i] = make_unique<Pawn>(Color::White);
        board[6][i] = make_unique<Pawn>(Color::Black);
    }
    // WHITE
    board[0][0] = move(make_unique<Rook>(Color::White));
    board[0][1] = move(make_unique<Knight>(Color::White));
    board[0][2] = move(make_unique<Bishop>(Color::White));
    board[0][3] = move(make_unique<Queen>(Color::White));
    board[0][4] = move(make_unique<King>(Color::White));
    board[0][5] = move(make_unique<Bishop>(Color::White));
    board[0][6] = move(make_unique<Knight>(Color::White));
    board[0][7] = move(make_unique<Rook>(Color::White));
    
    // BLACK
    board[7][0] = move(make_unique<Rook>(Color::Black));
    board[7][1] = move(make_unique<Knight>(Color::Black));
    board[7][2] = move(make_unique<Bishop>(Color::Black));
    board[7][3] = move(make_unique<Queen>(Color::Black));
    board[7][4] = move(make_unique<King>(Color::Black));
    board[7][5] = move(make_unique<Bishop>(Color::Black));
    board[7][6] = move(make_unique<Knight>(Color::Black));
    board[7][7] = move(make_unique<Rook>(Color::Black));
    
    
    // SETS THE REST TO NULLPTR;
    for (int row = 2; row < 6; row++) {
        for (int col = 0; col < 7; col ++)
            board[row][col] = nullptr;
    }
    
    /*
    int row_count = 0;
    for (auto& row : board)
    {
        int col_count = 0;
        for (auto& piece : row)
        {
            if (has_start_piece(row_count))
            {
                
                //auto temp_piece = get_start_piece(row_count, col_count);
                
                //board[row_count][col_count] = move(temp_piece);
            }
            col_count++;
        }
        row_count++;
    }
     */
    
}

bool Chess::try_move_piece() {
    bool correct_number_of_maked_pieces = (number_of_marked_tiles == 2);
    assert(correct_number_of_maked_pieces);
    if (number_of_marked_tiles == 2) {
        if (is_leagal_move()){
            cout << "Trying to move piece (" << first_marked_piece->pos_y << ", " << first_marked_piece->pos_x
                << ") to (" << second_marked_piece->pos_y <<", " <<  second_marked_piece->pos_x << ")" << endl;
            board[second_marked_piece->pos_y][second_marked_piece->pos_x] = move(board[first_marked_piece->pos_y][first_marked_piece->pos_x]);
            first_marked_piece = nullptr;
            second_marked_piece = nullptr;
            number_of_marked_tiles = 0;
            return true;
        }
        
    }
    else return false;
}



void Chess::piece_on_tile(int row, int col, Color& color, Chess_piece& piece_to_draw) const{
    color = board[row][col]->get_color();
    piece_to_draw = board[row][col]->get_type();
}

void Chess::list_all_pieces() const
{
    for (const auto& row : board)
    {
        for (const auto& piece : row)
        {
            if (piece != nullptr)
            {
                std::cout << piece->to_string() << std::endl;
            }
        }
    }
}

/* void Chess::reset_maked_tiles() {
    for (auto row : marked_tiles)
        for (auto value : row) {
            value = false;
        }
*/// }


void Chess::set_marked_tile(int row, int col) {
    bool correct_marked = (number_of_marked_tiles >= 0 || number_of_marked_tiles <= 2);
    
    assert(correct_marked);
    if (!first_marked_piece) {
        first_marked_piece = move(make_unique<Position>(row, col));
        number_of_marked_tiles = 1;
        // cout << "number_of_marked_tiles" << number_of_marked_tiles << "bool: " << correct_marked << endl;
    }
    
    
    else if (!second_marked_piece) {
        Position pos2 = Position{row, col};
        second_marked_piece = move(make_unique<Position>(row, col));
        number_of_marked_tiles = 2;
    }
    else assert(false && "Already marked pieces!");
    /*
    if (!marked_tiles[row][col])
    {
        marked_tiles[row][col] = true;
        number_of_marked_tiles++;
    }
    else{
        marked_tiles[row][col] = false;
        number_of_marked_tiles--;
    }
    */
}


void Chess::change_players_turn() {
    if (players_turn == Color::White){
        players_turn = Color::Black;
        cout << "Blacks turn" << endl;
    }
    else{
        players_turn = Color::White;
        cout << "Whites turn" << endl;
    }
}


bool Chess::is_piece(int row, int col, Color color, Chess_piece type) const
{   if (!board[row][col])
    {
        cout << "tried to find nullptr" << endl;;
        return false;
    }
    if (board[row][col]->get_type() == type && board[row][col]->get_color() == color)
    {
        return true;
    }
    else return false;
}

bool Chess::is_piece_nullptr(int row, int col) const
{
    if (board[row][col] == nullptr) return true;
    else return false;
}


std::unique_ptr<Piece> get_start_piece(int row, int col)
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
    
    Color color; // 1 = black, 0 = white
    if (black_start_row){
        color = Color::Black;
    }
    else color = Color::White;
    
    
    if (pawn) return move(make_unique<Pawn>(color));
    if (rook) return move(make_unique<Pawn>(color));
    if (knight) return move(make_unique<Pawn>(color));
    if (bishop) return move(make_unique<Pawn>(color));
    if (queen) return move(make_unique<Pawn>(color));
    if (king) return move(make_unique<Pawn>(color));
}

bool Chess::has_start_piece(int row) const
{
    if (row == 0 || row == 1 || row == 6 || row == 7)
        return true;
    
    else return false;
}
/*
// Chess::~Chess()
{
    for (auto row : board)
    {
        for (auto tile : row)
        {
            delete tile;
        }
    }
}
*/








