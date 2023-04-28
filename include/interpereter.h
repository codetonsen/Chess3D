//
// Created by Magnus Antonsen on 26/04/2023.
//

#ifndef CHESS3D_INTERPERETER_H
#define CHESS3D_INTERPERETER_H

#endif //CHESS3D_INTERPERETER_H
#include <iostream>
#include <filesystem>
#include <piece.h>
#include <vector>
#include <fstream>
class Interpereter{
public:
    Interpereter(){
        std::cout << "interpereter created" << std::endl;
    }

    // returns a vector of a pair with type and position.
    std::vector<std::pair<std::pair<PIECETYPE, PIECECOLOR>, std::pair<int,int>>> readFile(std::string path){
        std::string inputFEM = "";

        //Opens file from path given as argument and adds it to inputFEM. it only takes 1 line.
        std::ifstream inputFile(path);
        if (inputFile.is_open()) {
            std::getline(inputFile,inputFEM);

            inputFile.close(); // Close the file
        }
        else {
            std::cerr << "Failed to open file." << std::endl;
        }
        // Add file to object
        // Return true
        // Save as a do list for board class
        std::cout << inputFEM << std::endl;


        std::vector<std::pair<std::pair<PIECETYPE, PIECECOLOR>, std::pair<int, int>>> piecePositions; // Initialize the vector to store the piece positions


        int rank = 8, file = 1;
        for (char c : inputFEM) {
            if (isdigit(c)) { // If the character is a digit, skip that many squares
                file += c - '0';
            }
            else if (c == '/') { // If the character is a slash, move to the next rank and reset the file
                rank--;
                file = 1;
            }
            else if (c == ' ') {
                break;
            }
            else { // Otherwise, add the piece to the vector with its position
                PIECETYPE pieceType;
                PIECECOLOR pieceColor;
                switch (c) {
                    case 'P': pieceType = PAWN; pieceColor = WHITE;  break;
                    case 'N': pieceType = KNIGHT; pieceColor = WHITE; break;
                    case 'B': pieceType = BISHOP; pieceColor = WHITE; break;
                    case 'R': pieceType = ROOK; pieceColor = WHITE; break;
                    case 'Q': pieceType = QUEEN; pieceColor = WHITE; break;
                    case 'K': pieceType = KING; pieceColor = WHITE; break;
                    case 'p': pieceType = PAWN; pieceColor = BLACK; break;
                    case 'n': pieceType = KNIGHT; pieceColor = BLACK; break;
                    case 'b': pieceType = BISHOP; pieceColor = BLACK; break;
                    case 'r': pieceType = ROOK; pieceColor = BLACK; break;
                    case 'q': pieceType = QUEEN; pieceColor = BLACK; break;
                    case 'k': pieceType = KING; pieceColor = BLACK; break;
                    default: continue;
                }
                piecePositions.push_back(std::make_pair(std::make_pair(pieceType, pieceColor), std::make_pair(file-1, rank-1)));
                file++;
            }
        }
        return piecePositions;


    }


private:

    std::filesystem::path path_;

};