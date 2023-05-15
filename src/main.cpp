#include <iostream>

#include "../include/board.h"
#include "threepp/threepp.hpp"
#include "../include/graphics.h"
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


bool chosenPiece = false;
bool startSelect = false;
using namespace threepp;

namespace {
    struct MyListener: MouseListener {
        float &t;
        explicit MyListener(float &t) : t(t) {}

        void onMouseDown(int button, const Vector2& pos) override {
            std::cout << "onMouseDown, button= " << button << ", pos=" << pos << " at t=" << t << std::endl;
        }

        void onMouseUp(int button, const Vector2& pos) override {
            if(button == 0){
                startSelect = true;
            }


            std::cout << "onMouseUp, button= " << button << ", pos=" << pos << " at t=" << t << std::endl;
        }

        void onMouseMove(const Vector2& pos) override {
            //std::cout << "onMouseMove, " << "pos=" << pos << " at t=" << t << std::endl;
        }

        void onMouseWheel(const Vector2& delta) override {}
    };

}

int main() {

    // For now im using a global variable for "Selected object"
    Object3D* selected;

    Board board;
    board.initializeWithFEM("/Users/mac_m2/CLionProjects/AIS1002/Chess3D_old/data/games/startPosition.txt");
    //board.initialize();


    Canvas canvas;
    GLRenderer renderer{canvas};


    // Mouse listener to normalize input
    Vector2 mouse{-Infinity<float>, -Infinity<float>};
    MouseMoveListener mouseListener([&](auto &pos) {
        auto size = canvas.getSize();
        mouse.x = (pos.x / static_cast<float>(size.width)) * 2 - 1;
        mouse.y = -(pos.y / static_cast<float>(size.height)) * 2 + 1;
    });

    float t = 0;
    MyListener l{t};

    canvas.addMouseListener(&l);
    canvas.addMouseListener(&mouseListener);










    auto scene = Scene::create();
    auto camera = PerspectiveCamera::create(75, canvas.getAspect(), 0.1f, 100);
    camera->position.z = 5;
    camera->position.y = 5;


    Graphics graphics(scene, board);

    OrbitControls controls{camera, canvas};

    /*
    {
        auto geo = BoxGeometry::create(2,2,2);
        auto material = MeshBasicMaterial::create();
        material->color.setRGB(100,100,100);
        auto mesh = Mesh::create(geo, material);
        mesh->position.set()
    }
    */




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
            std::cout << "created plane at x,y: " << rank-3.5 << file -3.5 << std::endl;
        }
    }

    // Imports the correct assets and places them appropriatly at the board
    // TODO: Make a function that can do this after each move


    auto startBoard = board.getBoard();


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



    auto pieces = Group::create();
    for(int i = 0; i<8; i++) {
        for (int j = 0; j<8; j++) {
            if (startBoard[i][j]) {

                auto type = startBoard[i][j]->getType();
                auto color = startBoard[i][j]->getColor();
                auto position = std::make_pair(i, j);
                graphics.addPiece(position, type, color, loader);

            }

        }
    }


    canvas.onWindowResize([&](WindowSize size) {
        camera->aspect = size.getAspect();
        camera->updateProjectionMatrix();
        renderer.setSize(size);
    });


    Raycaster raycaster;


    std::pair<int, int> selectedPosition;

    canvas.animate([&](float dt) {
        auto myBoard = board.getBoard();
        // MouseDown triggers raycast event


        if (selectedPosition.first != -1) {


            if (chosenPiece) {
                if (startSelect) {
                    raycaster.setFromCamera(mouse, camera);
                    auto intersects = raycaster.intersectObjects(scene->children);
                    if (!intersects.empty()) {
                        auto &intersected = intersects.front();
                        selected = intersected.object;

                        auto position = selected->position;
                        float file = position[0];
                        float rank = position[2];
                        file = file + 3.5;
                        rank = rank + 3.5;
                        std::cout << "In the chosen Piece now hovering over x,y: " << file << " " << rank << std::endl;


                        auto boardPosition = std::make_pair(int(file), int(rank));


                        auto validMoves = board.getAllPieceMoves(selectedPosition);
                        for (auto move: validMoves) {
                            if (move == boardPosition) {

                                auto curPiece = myBoard[selectedPosition.first][selectedPosition.second];

                                graphics.removeValidMoves();
                                graphics.movePiece(selectedPosition, boardPosition, curPiece->getType(),
                                                   curPiece->getColor(), loader);
                                //graphics.addPiece(boardPosition, curPiece->getType(), curPiece->getColor(), loader);
                                board.move(selectedPosition.first, selectedPosition.second, boardPosition.first,
                                           boardPosition.second);

                                selectedPosition = {-1,-1};
                            }
                        }
                        chosenPiece = false;

                    }

                }

            }
        }
        if (startSelect) {

            raycaster.setFromCamera(mouse, camera);
            auto intersects = raycaster.intersectObjects(scene->children);
            if (!intersects.empty()) {
                auto &intersected = intersects.front();
                selected = intersected.object;

                auto position = selected->position;
                float file = position[0];
                float rank = position[2];
                file = file + 3.5;
                rank = rank + 3.5;
                std::cout << "hovering over x,y: " << file << " " << rank << std::endl;


                auto boardPosition = std::make_pair(int(file), int(rank));


                // This just removes pieces graphically and in the board object.
                if (myBoard[int(file)][int(rank)]) {
                    // Checks for all valid moves, and shows them graphically
                    selectedPosition = boardPosition;
                    auto validMoves = board.getAllPieceMoves(boardPosition);
                    auto validMovesGroup = Group::create();
                    graphics.showValidMoves(validMoves);
                    /*
                    for(auto i : validMoves) {
                        auto validMoveGeo = BoxGeometry::create(0.5,0.5,0.5);
                        auto validMoveMaterial = MeshBasicMaterial::create();
                        validMoveMaterial->color.setRGB(124,252,0);
                        auto validMoveMesh = Mesh::create(validMoveGeo, validMoveMaterial);
                        validMoveMesh->position.set(i.first-3.5,1.5,i.second-3.5);
                        validMovesGroup->add(validMoveMesh);
                    }
                    scene->add(validMovesGroup);*/

                    chosenPiece = true;

                }


            }

            startSelect = false;
        }
        renderer.render(scene, camera);
    });
}
