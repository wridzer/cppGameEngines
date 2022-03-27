#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <iostream>
#include <Godot.hpp>
#include <Control.hpp>
#include "Enemy.h"
#include <vector>

using namespace godot;

class GameManager : public Node2D{
    GODOT_CLASS(GameManager, Node2D)
public:
    GameManager();
    ~GameManager();
    
    int enimNumber = 5;
    Node2D* enemyInstance;
    static void _register_methods();
    void _process(float delta);
private:
    std::vector<Node2D*> enimList;
};

#endif