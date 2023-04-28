//
// Created by Magnus Antonsen on 07/04/2023.
//

#ifndef CHESS3D_ROOK_H
#define CHESS3D_ROOK_H

#endif //CHESS3D_ROOK_H

#include "piece.h"

class Rook : public Piece{
public:
    Rook(PIECECOLOR color, int rank, int file) : Piece(color, PIECETYPE::ROOK) {
        std::cout << "CREATED ROOK at position (x,y):" << rank << " " << file << std::endl;
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

        // Rooks can move everywhere on its rank or file
        // Logic for rank slide
        if (rank_ == endRank or file_ == endFile) {
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