//
// Created by Magnus Antonsen on 07/04/2023.
//

#ifndef CHESS3D_QUEEN_H
#define CHESS3D_QUEEN_H

#endif //CHESS3D_QUEEN_H
#include "piece.h"

class Queen : public Piece {
public:
    Queen(PIECECOLOR color, int rank, int file) : Piece(color, PIECETYPE::QUEEN) {
        std::cout << "CREATED QUEEN at position (x,y):" << rank << " " << file << std::endl;
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

        // QUEENS can move in all directions across the board
        // NORTH/SOUTH/WEST/EAST check and diagonal.
        if (file_ == endFile or rank_ == endRank or abs(rank_ - endRank) == abs(file_ - endFile)) {
            return true;
        } else {
            return false;
        }



    }
private:
    int rank_;
    int file_;
    bool isSliding = true;

};