//
// Created by Magnus Antonsen on 07/04/2023.
//

#ifndef CHESS3D_BOARD_H
#define CHESS3D_BOARD_H
#include <memory>
#include <array>
#include <vector>
#include <iostream>


#include "piece.h"
#include "bishop.h"
#include "rook.h"
#include "queen.h"
#include "knight.h"
#include "king.h"
#include "pawn.h"
#include "interpereter.h"
class Board{
public:
    Board(){std::cout << "BOARD CREATED" << std::endl;}

    // GET
    std::vector<std::string> getHistory(){
        return moveHistory_;
    }

    std::shared_ptr<Piece> getPiece(std::pair<int, int> position) {
        return board_[position.first][position.second];
    }

    void printBoard(){
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board_[i][j] != nullptr){
                    std::cout << board_[i][j]->getType() << std::endl;
                }
            }
        }
    }

    // SET

    void addMove(std::string move){
        moveHistory_.emplace_back(move);
    }

    // DEEP LOGIC

    void move(int rank, int file, int endRank, int endFile) {
        auto curPiece = getPiece(std::make_pair(rank, file));
        std::cout << curPiece->isValidMove(endRank, endFile) << std::endl;

    }

    void addPiece(std::pair<PIECETYPE, PIECECOLOR> info, std::pair<int, int> position) {
        // Can apparently not use info.first etc. in the make shared argument. Therefore I will need a switch function
        //board_[position.first][position.second] = std::make_shared<info.first>(info.second,position.first,position.second);
        switch(info.first) {
            case PIECETYPE::PAWN:
                board_[position.first][position.second] = std::make_shared<Pawn>(info.second,position.first,position.second);
                break;
            case PIECETYPE::ROOK:
                board_[position.first][position.second] = std::make_shared<Rook>(info.second,position.first,position.second);
                break;
            case PIECETYPE::KNIGHT:
                board_[position.first][position.second] = std::make_shared<Knight>(info.second,position.first,position.second);
                break;
            case PIECETYPE::BISHOP:
                board_[position.first][position.second] = std::make_shared<Bishop>(info.second,position.first,position.second);
                break;
            case PIECETYPE::QUEEN:
                board_[position.first][position.second] = std::make_shared<Queen>(info.second,position.first,position.second);
                break;
            case PIECETYPE::KING:
                board_[position.first][position.second] = std::make_shared<King>(info.second,position.first,position.second);
                break;
            default:
                break;
        }
    }

    std::vector<std::pair<int, int>> getAllPieceMoves(std::pair<int, int> position) {

        auto curPiece = getPiece(position);
        std::vector<std::pair<int, int>> piecePositions;
        std::vector<std::pair<int, int>> enemyPositions;
        std::cout << "Checking for all valid moves" << std::endl;

        // Loops through board to get a list of coordinates where all pieces are.
        for (int file = 0; file < 8; file++) {
            for (int rank = 0; rank < 8; rank++) {
                if (board_[rank][file] != nullptr) {
                    piecePositions.emplace_back(std::make_pair(rank,file));
                    // Checks for enemy positions
                    if (board_[rank][file]->getColor() != curPiece->getColor()) {
                        enemyPositions.emplace_back(std::make_pair(rank, file));
                    }
                }
            }
        }
        piecePositions_ = piecePositions;
        int count = 1;
        for (int file = 0; file < 8; file++) {
            for (int rank = 0; rank < 8; rank++) {
                if (curPiece->isValidMove(rank, file)) {

                    std::cout << "valid move at " << rank << ", " << file << std::endl;
                } else {
                    //std::cout << count << std::endl;
                    //std::cout << "NOT valid move at" << rank << ", " << file << std::endl;
                    count++;
                }


            }
        }



        return piecePositions;
    }

    void initializeWithFEM(std::string path){
        Interpereter reader;
        auto FEM = reader.readFile(path);
        for (auto piece : FEM) {
            std::cout << "Piece type: " << piece.first.first << ", color: " << piece.first.second << ", position: (" << piece.second.first << ", " << piece.second.second << ")" << std::endl;
        }


    }
    void initialize(){

        //Place the pawns at black and white
        for (int i = 0; i < 8; i++) {
            board_[i][1] = std::make_shared<Pawn>(PIECECOLOR::WHITE, i, 1);
            board_[i][6] = std::make_shared<Pawn>(PIECECOLOR::BLACK, i, 6);
        }

        // Place rooks
        board_[0][0] = std::make_shared<Rook>(PIECECOLOR::WHITE, 0, 0);
        board_[7][0] = std::make_shared<Rook>(PIECECOLOR::WHITE, 7, 0);
        board_[0][7] = std::make_shared<Rook>(PIECECOLOR::BLACK, 0, 7);
        board_[7][7] = std::make_shared<Rook>(PIECECOLOR::BLACK, 7, 7);

        // Place Knights
        board_[1][0] = std::make_shared<Knight>(PIECECOLOR::WHITE, 1, 0);
        board_[6][0] = std::make_shared<Knight>(PIECECOLOR::WHITE, 6, 0);
        board_[1][7] = std::make_shared<Knight>(PIECECOLOR::BLACK, 1, 7);
        board_[6][7] = std::make_shared<Knight>(PIECECOLOR::BLACK, 6, 7);

        // Place Bishops
        board_[2][0] = std::make_shared<Rook>(PIECECOLOR::WHITE, 2, 0);
        board_[5][0] = std::make_shared<Rook>(PIECECOLOR::WHITE, 5, 0);
        board_[2][7] = std::make_shared<Rook>(PIECECOLOR::BLACK, 2, 7);
        board_[5][7] = std::make_shared<Rook>(PIECECOLOR::BLACK, 5, 7);

        // Place Queens
        board_[3][0] = std::make_shared<Queen>(PIECECOLOR::WHITE, 3, 0);
        board_[3][7] = std::make_shared<Queen>(PIECECOLOR::BLACK, 3, 7);

        // Place Kings
        board_[4][0] = std::make_shared<King>(PIECECOLOR::WHITE, 4, 0);
        board_[4][7] = std::make_shared<King>(PIECECOLOR::BLACK, 4, 7);


    }



private:
    int boardSize = 8;
    int playerCount = 2;
    std::vector<std::pair<int, int>> piecePositions_;
    std::vector<std::string> moveHistory_;
    std::shared_ptr<Piece> board_[8][8];
};
#endif //CHESS3D_BOARD_H
