//
// Created by Magnus Antonsen on 07/04/2023.
//

#ifndef CHESS3D_PAWN_H
#define CHESS3D_PAWN_H
#include <iostream>
#include <vector>
#include "piece.h"

class Pawn : public Piece {
public:
    Pawn(PIECECOLOR color, int rank, int file) : Piece(color, PIECETYPE::PAWN) {
        std::cout << "CREATED PAWN at position(x,y): " << rank << " " << file << std::endl;
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
        if(endRank > 8 or endFile > 8) {
            std::cout << "out of bounds \n";
            return false; // Returns false because out of bounds
        };
        int deltaRank = rank_ - endRank;
        int deltaFile = file_ - endFile;

        //std::cout << "deltaRank: " << deltaRank << "deltaFile: " << deltaFile << std::endl;
        // ONE FORWARD
        if (deltaRank == 0 and deltaFile == -1) {
            hasMoved_ = true;
            return true;
        }
        // TWO FORWARD
        if (getColor() == PIECECOLOR::WHITE and file_ == 1) {
            if (deltaRank == 0 and deltaFile == -2) {
                return true;
            }
        }

        //ATTACK

        if (abs(deltaRank) == 1 and deltaFile == -1) {
            hasMoved_ = true;
            return true;
        }



        //TODO: EN PEASSANT


    }

private:
    bool hasMoved_ = false;
    int rank_ = 0;
    int file_ = 0;
};
#endif //CHESS3D_PAWN_H
