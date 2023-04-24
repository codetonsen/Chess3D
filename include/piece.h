//
// Created by Magnus Antonsen on 07/04/2023.
//

#ifndef CHESS3D_PIECE_H
#define CHESS3D_PIECE_H
#include <iostream>


enum PIECETYPE{
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};
// Using enum here will return 0/1 depending on what color. White is 0, black is 1.
enum PIECECOLOR{
    WHITE,
    BLACK
};

class Piece{
public:
    Piece(PIECECOLOR color, PIECETYPE type){
        color_ = color;
    }

    // GETTERS
    PIECECOLOR getColor(){
        return color_;
    }
    PIECETYPE getType(){
        return type_;
    }

    bool isValidMove(int start){

    }

private:
    PIECECOLOR color_;
    PIECETYPE type_;
};
#endif //CHESS3D_PIECE_H
