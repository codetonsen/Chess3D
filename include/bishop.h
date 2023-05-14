//
// Created by Magnus Antonsen on 07/04/2023.
//

#ifndef CHESS3D_BISHOP_H
#define CHESS3D_BISHOP_H

#endif //CHESS3D_BISHOP_H

#include "piece.h"

class Bishop : public Piece {
public:
    Bishop(PIECECOLOR color, int rank, int file) : Piece(color, PIECETYPE::BISHOP) {
        std::cout << "CREATED BISHOP at (x,y):" << rank << " " << file << std::endl;
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
        }

        // Check for diagonal moves
        if (abs(rank_ - endRank) == abs(file_ - endFile)) {
            std::cout << "bishop" << std::endl;

            //TODO check for collision


            return true;
        }



    }
private:
    bool isSliding_ = true;
    int rank_; //Horizontal (x)
    int file_; //Vertical (y)

};