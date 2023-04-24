#include <iostream>
#include "../include/piece.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    Piece testPiece(PIECECOLOR::BLACK,PIECETYPE::BISHOP);
    std::cout << testPiece.getColor() << std::endl;

    return 0;;
}
