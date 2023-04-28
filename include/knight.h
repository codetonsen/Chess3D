//
// Created by Magnus Antonsen on 07/04/2023.
//

#ifndef CHESS3D_KNIGHT_H
#define CHESS3D_KNIGHT_H

#endif //CHESS3D_KNIGHT_H
#include "piece.h"

class Knight : public Piece {
public:
    Knight(PIECECOLOR color, int rank, int file) : Piece(color, PIECETYPE::KNIGHT) {
        std::cout << "CREATED KNIGHT at position(x,y): " << rank << " " << file << std::endl;
        rank_ = rank;
        file_ = file;
    }
    void move(int endRank, int endFile) {
        if (isValidMove(endRank, endFile)) {
            rank_ = endRank;
            file_ = endFile;
        }
    }

    std::pair<int, int> getPos(){
        std::pair<int, int> position;
        position.first = rank_;
        position.second = file_;
        return position;
    }

    bool isValidMove(int endRank, int endFile) {
        // Check if out of bounds
        if(endRank > 8 or endFile > 8) {
            return false; // Returns false because out of bounds
        };

        // KNIGHTS can move in 6 different L shapes
        // They move at x+-1 and y+-2 or x+-2 and y+-1 i think
        int deltaRank = rank_ - endRank;
        int deltaFile = file_ - endFile;

        if (abs(deltaRank) == 1 and abs(deltaFile) == 2) {
            return true;
        }
        if (abs(deltaRank) == 2 and abs(deltaFile) == 1) {
            return true;
        }

        return false;

    }
private:
    int rank_;
    int file_;
};