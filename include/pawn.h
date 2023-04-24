//
// Created by Magnus Antonsen on 07/04/2023.
//

#ifndef CHESS3D_PAWN_H
#define CHESS3D_PAWN_H
#include <iostream>
#include "piece.h"
class Pawn : public Piece {
public:
    Pawn(std::string color) : Piece(color) {
        color_ = color;
    }
private:
    std::string color_;

};
#endif //CHESS3D_PAWN_H
