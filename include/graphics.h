//
// Created by Magnus Antonsen on 09/05/2023.
//

#ifndef CHESS3D_GRAPHICS_H
#define CHESS3D_GRAPHICS_H

#endif //CHESS3D_GRAPHICS_H
#include "board.h"
#include "threepp/threepp.hpp"
#include <array>
#include <vector>
using namespace threepp;

class Graphics {
public:
    //Constructor
    Graphics(std::shared_ptr<Scene> scene, Board board) {
        scene_ = scene;
        board_ = std::make_shared<Board>(board);
    }

    void addPiece(std::pair<int,int> position, PIECETYPE type, PIECECOLOR color, OBJLoader loader) {

        // Adds chessPiece from models, depending on what type it is
        std::shared_ptr<threepp::Object3D> pieceModel;
        //std::shared_ptr<threepp::MeshBasicMaterial> blackMaterial;
        //blackMaterial->color.setRGB(0,0,0);
        //std::shared_ptr<threepp::MeshBasicMaterial> whiteMaterial;
        //whiteMaterial->color.setRGB(255,255,255);
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
            /*
            auto mesh = std::dynamic_pointer_cast<Mesh>(pieceModel);
            auto geometry = mesh->geometry();
            auto fullMesh = Mesh::create(geometry, whiteMaterial);
            auto material = mesh->material()->as<MeshBasicMaterial>();

            switch (color) {
                case PIECECOLOR::WHITE:
                    material->color.setRGB(255,255,255);
                case PIECECOLOR::BLACK:
                    material->color.setRGB(20,20,20);
                default:
                    break;
            }*/
            pieceModel->position.set(position.first - 3.5, 0, position.second - 3.5);
            pieceModel->scale.set(pieceScale, pieceScale, pieceScale);
            pieceModel->name = std::to_string(position.first)+ std::to_string(position.second);

            scene_->add(pieceModel);
            auto name = std::to_string(position.first)+std::to_string(position.second);
            std::cout << name << std::endl;
            positions[position.first][position.second] = std::make_pair(position, name);

        }



        /*
        auto testGeometry = BoxGeometry::create(1,1,1);
        auto testMaterial = MeshBasicMaterial::create();
        testMaterial->color.setRGB(255,150,150);
        auto testMesh = Mesh::create(testGeometry,testMaterial);
        testMesh->name = "test";
        scene_->add(testMesh);
        positions[position.first][position.second] = std::make_pair(position, "test");*/
    }
    void removePiece(std::pair<int, int> position) {
        auto nameOfSelected = positions[position.first][position.second].second;
        auto selectedObject = scene_->getObjectByName(nameOfSelected);
        selectedObject->position.set(0,5,0);
        scene_->remove(selectedObject);

        std::pair<std::pair<int, int>, std::string> empty;
        positions[position.first][position.second] = empty;

    }
    void movePiece(std::pair<int, int> start, std::pair<int, int> end, PIECETYPE type, PIECECOLOR color, OBJLoader loader) {
        removePiece(start);
        addPiece(end, type, color, loader);
    }


    void showValidMoves(std::vector<std::pair<int, int>> validMoves) {
        for (auto pos : validMoves) {
            auto validMoveGeo = BoxGeometry::create(0.5,0.5,0.5);
            auto validMoveMaterial = MeshBasicMaterial::create();
            validMoveMaterial->color.setRGB(124,252,0);
            auto validMoveMesh = Mesh::create(validMoveGeo, validMoveMaterial);
            validMoveMesh->position.set(pos.first-3.5,1,pos.second-3.5);
            validMoveMesh->name = "validMove";
            validMoveObjects.emplace_back(validMoveMesh);
            scene_->add(validMoveMesh);
        }
    }
    void removeValidMoves() {
        for (auto obj : validMoveObjects) {
            scene_->remove(obj);
        }

    }

private:
    std::pair<std::pair<int, int>, std::string> positions[8][8];
    std::shared_ptr<Scene> scene_;
    std::shared_ptr<Board> board_;
    std::vector<std::shared_ptr<Object3D>> validMoveObjects;
    float pieceScale = 0.4;
};