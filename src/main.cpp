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

/*
int main(){
    Board board;
    board.initializeWithFEM("/Users/mac_m2/CLionProjects/AIS1002/Chess3D_old/data/games/startPosition.txt");
    board.printBoard();

    auto validMoves = board.getAllPieceMoves(std::make_pair(1,5));
    std::cout << validMoves.size() << std::endl;

    return 1;
}
*/

// GRAPHICS

using namespace threepp;





int main() {

    // For now im using a global variable for "Selected object"
    Object3D* selected;

    Board board;
    board.initializeWithFEM("/Users/mac_m2/CLionProjects/AIS1002/Chess3D_old/data/games/startPosition.txt");



    Canvas canvas;
    GLRenderer renderer{canvas};

    // Mouse listener
    Vector2 mouse{-Infinity<float>, -Infinity<float>};
    MouseMoveListener l([&](Vector2 pos) {
        // calculate mouse position in normalized device coordinates
        // (-1 to +1) for both components

        auto size = canvas.getSize();
        mouse.x = (pos.x / static_cast<float>(size.width)) * 2 - 1;
        mouse.y = -(pos.y / static_cast<float>(size.height)) * 2 + 1;

    });



    canvas.addMouseListener(&l);





    auto scene = Scene::create();
    auto camera = PerspectiveCamera::create(75, canvas.getAspect(), 0.1f, 100);
    camera->position.z = 5;
    camera->position.y = 5;

    OrbitControls controls{camera, canvas};





    std::pair<int, int> testPos = {0, 1};
    auto validMoves = board.getAllPieceMoves(testPos);


    //auto light = HemisphereLight::create();
    //scene->add(light);

    // Makes the board tiles.
    auto planeGroup = Group::create();
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
            planeGroup->add(plane);
            scene->add(plane);
        }
    }

    // Imports the correct assets and places them appropriatly at the board
    // TODO: Make a function that can do this after each move


    auto myBoard = board.getBoard();
    /*
    auto getPOSs =  myBoard[0][1]->getPos();
    std::cout << myBoard[0][2]->isValidMove(0,2) << std::endl;
    std::cout << "This is what the piece thinks: " << getPOSs.first << " " << getPOSs.second << std::endl;
    {
        auto getPOSs =  myBoard[1][1]->getPos();
        std::cout << "This is what the piece thinks: " << getPOSs.first << " " << getPOSs.second << std::endl;
    }
    {
        auto getPOSs =  myBoard[2][0]->getPos();
        std::cout << "This is what the piece thinks: " << getPOSs.first << " " << getPOSs.second << std::endl;
    }
    */

    // LIGHTING
    auto light2 = SpotLight::create(Color::teal);
    light2->distance = 400;
    light2->angle = math::degToRad(20);
    light2->position.set(10, 10, 0);
    light2->castShadow = true;
    scene->add(light2);
    {
        auto light2 = SpotLight::create(Color::orange);
        light2->distance = 400;
        light2->angle = math::degToRad(20);
        light2->position.set(-10, 6, -10);
        light2->castShadow = true;
        scene->add(light2);
    }


    // Loading objects
    OBJLoader loader;


    auto boardGeometry = loader.load("models/aestetic_table.obj");
    scene->add(boardGeometry);

    auto kingGeometry = loader.load("models/newKing.obj");

    auto kings = Group::create();
    for(int i = 0; i<8; i++) {
        for (int j = 0; j<8; j++) {
            if (myBoard[i][j]) {
                auto type = myBoard[i][j]->getType();
                std::shared_ptr<threepp::Object3D> pieceModel;

                // Switches once again between the different types, to load the spesific path to the 3d-model
                switch (type) {
                    case PIECETYPE::PAWN:
                        pieceModel = loader.load("models/Pawn.obj");
                        break;
                    case PIECETYPE::KING:
                        pieceModel = loader.load("models/Pawn.obj");
                        break;
                    case PIECETYPE::QUEEN:
                        pieceModel = loader.load("models/Queen.obj");
                        break;
                    case PIECETYPE::ROOK:
                        pieceModel = loader.load("models/Rook.obj");
                        break;
                    case PIECETYPE::KNIGHT:
                        pieceModel = loader.load("models/Knight.obj");
                        break;
                    case PIECETYPE::BISHOP:
                        pieceModel = loader.load("models/Bishop.obj");
                        break;
                    default:
                        break;
                }

                if (pieceModel) {

                    pieceModel->position.set(i - 3.5, 0, j - 3.5);
                    pieceModel->scale.set(0.4, 0.4, 0.4);

                    scene->add(pieceModel);
                }
            }

        }
    }

    canvas.onWindowResize([&](WindowSize size) {
        camera->aspect = size.getAspect();
        camera->updateProjectionMatrix();
        renderer.setSize(size);
    });


    Raycaster raycaster;


    canvas.animate([&](float dt) {
        raycaster.setFromCamera(mouse,camera);
        auto intersects = raycaster.intersectObjects(scene->children);
        if (!intersects.empty()) {
            auto& intersected = intersects.front();
            selected = intersected.object;
            selected->position.setY(2);
        }

        renderer.render(scene, camera);
    });
}
