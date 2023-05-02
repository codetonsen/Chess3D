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

// Took this mouse listener struct from the example at https://github.com/markaren/threepp/blob/master/examples/misc/mouse_listener.cpp
namespace {

    struct MyListener: MouseListener {

        float& t;

        explicit MyListener(float& t): t(t) {}

        void onMouseDown(int button, const Vector2& pos) override {
            std::cout << "onMouseDown, button= " << button << ", pos=" << pos << " at t=" << t << std::endl;

        }

        void onMouseUp(int button, const Vector2& pos) override {
            std::cout << "onMouseUp, button= " << button << ", pos=" << pos << " at t=" << t << std::endl;
        }

        void onMouseMove(const Vector2& pos) override {
            std::cout << "onMouseMove, "
                      << "pos=" << pos << " at t=" << t << std::endl;
        }

        void onMouseWheel(const Vector2& delta) override {
            std::cout << "onMouseWheel, "
                      << "delta=" << delta << " at t=" << t << std::endl;
        }
    };

}




int main() {

    Board board;
    board.initializeWithFEM("/Users/mac_m2/CLionProjects/AIS1002/Chess3D_old/data/games/startPosition.txt");


    Canvas canvas;
    GLRenderer renderer{canvas};

    // Mouse listener
    float t = 0;
    MyListener l{t};
    canvas.addMouseListener(&l);



    auto scene = Scene::create();
    auto camera = PerspectiveCamera::create(75, canvas.getAspect(), 0.1f, 100);
    camera->position.z = 5;
    camera->position.y = 5;

    OrbitControls controls{camera, canvas};








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
                    /* //Materials for black and white, but i need to know more techinalities about this before implementing
                    auto material = MeshBasicMaterial::create();
                    if (myBoard[i][j]->getColor() == PIECECOLOR::WHITE) {
                        material->color.setRGB(255,255,255);
                    } else {
                        material->color.setRGB(165,42,42);
                    }
                    auto firstMaterial = pieceModel.get()->material();
                    */
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

    canvas.animate([&](float dt) {

        t+=dt;
        renderer.render(scene, camera);
    });
}