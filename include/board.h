//
// Created by Magnus Antonsen on 07/04/2023.
//

#ifndef CHESS3D_BOARD_H
#define CHESS3D_BOARD_H
#include <memory>
#include <array>
#include "../include/piece.h"
#include <iostream>
class Board{
public:
    std::shared_ptr<Piece> getPiece(int col, int row){
        // this can return a nullptr
        return board[col][row];
    }
    void movePiece(int startCol, int startRow, int endCol, int endRow){
        auto temp = board[startCol][startRow];
        board[startCol][startRow] = board[endCol][endRow];
        board[endCol][endRow] = temp;
        std::cout << "Moved Piece!" << std::endl;
    }
private:
    std::shared_ptr<Piece> board[8][8];
};
#endif //CHESS3D_BOARD_H
