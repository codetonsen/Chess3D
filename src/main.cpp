#include <iostream>

#include "../include/board.h"
#include "threepp/threepp.hpp"

// LOGIC
/*
int main() {
    //ROOK TEST
    Rook testRook(PIECECOLOR::WHITE, 0, 0);
    std::cout << "Color (0-Black, 1-White): " << testRook.getColor() << std::endl;
    testRook.move(0,7);
    std::cout << testRook.getPos().first << " " << testRook.getPos().second << std::endl;
    testRook.move(6,7);
    std::cout << testRook.getPos().first << " " << testRook.getPos().second << std::endl;
    testRook.move(6,2);
    std::cout << testRook.getPos().first << " " << testRook.getPos().second << std::endl;


    //BISHOP TEST
    Bishop testBishop(PIECECOLOR::BLACK, 2, 0);
    std::cout << "Color (0-Black, 1-White): " << testBishop.getColor() << std::endl;
    testBishop.move(1,1);
    std::cout << testBishop.getPos().first << " " << testBishop.getPos().second << std::endl;


    //QUEEN TEST
    Queen testQueen(PIECECOLOR::WHITE, 3, 0);
    std::cout << "Color (0-Black, 1-White): " << testQueen.getColor() << std::endl;
    testQueen.move(3,0);
    std::cout << testQueen.getPos().first << " " << testQueen.getPos().second << std::endl;
    testQueen.move(3,3);
    std::cout << testQueen.getPos().first << " " << testQueen.getPos().second << std::endl;
    testQueen.move(5,5);
    std::cout << testQueen.getPos().first << " " << testQueen.getPos().second << std::endl;
    testQueen.move(5,2);
    std::cout << testQueen.getPos().first << " " << testQueen.getPos().second << std::endl;
    testQueen.move(1,2);
    std::cout << testQueen.getPos().first << " " << testQueen.getPos().second << std::endl;
    testQueen.move(6,7);
    std::cout << testQueen.getPos().first << " " << testQueen.getPos().second << std::endl;

    //KNIGHT TEST
    Knight testKnigth(PIECECOLOR::WHITE, 1, 0);
    std::cout << "Color (0-Black, 1-White): " << testKnigth.getColor() << std::endl;
    testKnigth.move(0,2);
    std::cout << testKnigth.getPos().first << " " << testKnigth.getPos().second << std::endl;
    testKnigth.move(2,3);
    std::cout << testKnigth.getPos().first << " " << testKnigth.getPos().second << std::endl;
    testKnigth.move(4,2);
    std::cout << testKnigth.getPos().first << " " << testKnigth.getPos().second << std::endl;

    //KING TEST
    King testKing(PIECECOLOR::WHITE, 4, 0);
    std::cout << "Color (0-Black, 1-White): " << testKing.getColor() << std::endl;
    testKing.move(4,1);
    std::cout << testKing.getPos().first << " " << testKing.getPos().second << std::endl;
    testKing.move(3,1);
    std::cout << testKing.getPos().first << " " << testKing.getPos().second << std::endl;
    testKing.move(4,2);
    std::cout << testKing.getPos().first << " " << testKing.getPos().second << std::endl;


    // PAWN TEST
    Pawn testPawn(PIECECOLOR::WHITE, 4, 1);
    std::cout << "Color (0-Black, 1-White): " << testPawn.getColor() << std::endl;
    testPawn.move(4,3);
    std::cout << testPawn.getPos().first << " " << testPawn.getPos().second << std::endl;
    testPawn.move(4,4);
    std::cout << testPawn.getPos().first << " " << testPawn.getPos().second << std::endl;
    testPawn.move(3,5);
    std::cout << testPawn.getPos().first << " " << testPawn.getPos().second << std::endl;




    return 0;;
}
*/

int main(){
    Board board;
    board.initializeWithFEM("/Users/mac_m2/CLionProjects/AIS1002/Chess3D_old/data/games/startPosition.txt");
    board.printBoard();
    /*
    auto validMoves = board.getAllPieceMoves(std::make_pair(1,5));
    std::cout << validMoves.size() << std::endl;
*/
    return 1;
}


// GRAPHICS
/*
using namespace threepp;

int main() {

    Canvas canvas;
    GLRenderer renderer{canvas};

    auto scene = Scene::create();
    auto camera = PerspectiveCamera::create(75, canvas.getAspect(), 0.1f, 100);
    camera->position.z = 5;
    camera->position.y = 5;

    OrbitControls controls{camera, canvas};

    auto light = HemisphereLight::create();
    scene->add(light);

    for (int file = 0; file<8; file++) {
        for (int rank = 0; rank<8; rank++) {
            auto planeGeometry = PlaneGeometry::create(1,1);
            auto planeMaterial = MeshBasicMaterial::create();
            if ((file+rank) % 2) {
                planeMaterial->color.setRGB(0,0,0);
            } else {
                planeMaterial->color.setRGB(255,255,255);
            }
            auto plane = Mesh::create(planeGeometry, planeMaterial);
            plane->position.set(rank-3.5,0,file-3.5);
            plane->rotateX(math::degToRad(-90));
            scene->add(plane);
        }
    }

    canvas.onWindowResize([&](WindowSize size) {
        camera->aspect = size.getAspect();
        camera->updateProjectionMatrix();
        renderer.setSize(size);
    });

    canvas.animate([&]() {


        renderer.render(scene, camera);
    });
}*/