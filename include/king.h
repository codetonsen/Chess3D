//
// Created by Magnus Antonsen on 07/04/2023.
//

#ifndef CHESS3D_KING_H
#define CHESS3D_KING_H

#endif //CHESS3D_KING_H
#include "piece.h"

class King : public Piece{
public:
    King(PIECECOLOR color, int rank, int file) : Piece(color, PIECETYPE::KING) {
        std::cout << "CREATED KING at position (x,y):" << rank << " " << file << std::endl;
        rank_ = rank;
        file_ = file;
    }

    void move(int endRank, int endFile) {
        if (isValidMove(endRank, endFile)) {
            rank_ = endRank;
            file_ = endFile;
            // Run a method at board class
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

        // KINGS can move in every direction, but only one square
        int deltaRank = rank_ - endRank;
        int deltaFile = file_ - endFile;
        std::cout << "deltas (x,y): " << deltaRank << " " << deltaFile << std::endl;
        //CORNERS
        if(abs(deltaRank) == 1 and abs(deltaFile) == 1) {
            std::cout << "corner" << std::endl;
            return true;
        }
        //RIGHT LEFT
        if(abs(deltaRank) == 1 and abs(deltaFile) == 0) {
            std::cout << "right left" << std::endl;
            return true;
        }
        //TOP BOTTOM
        if(abs(deltaRank) == 0 and abs(deltaFile) == 1) {
            std::cout << "top bottom" << std::endl;
            return true;
        }

        return false;

    }
private:
    int rank_;
    int file_;
    bool isSliding = true;
};