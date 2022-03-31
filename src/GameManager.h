#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <iostream>
#include <Godot.hpp>
#include <Control.hpp>
#include "Enemy.h"
#include <vector>
#include <Ref.hpp>
#include <Node2D.hpp>
#include <Sprite.hpp>
#include <ResourceLoader.hpp>
#include <Label.hpp>
#include <PackedScene.hpp>
#include <Area2D.hpp>

using namespace godot;

class GameManager : public Node2D{
    GODOT_CLASS(GameManager, Node2D)
public:
    GameManager();
    ~GameManager();

    void EnemyDeleted();
    
    static void _register_methods();
    void _init();

    void _ready();
    void _process(float delta);
    void _physics_process(float delta);
    void _on_Player_hit(Area2D *area);


private:
    int enemyCounter;
    int enimNumber = 5;
    int score = 0;
    Ref<PackedScene> enemyInstance;
    std::vector<Node2D*> enimList;
};

#endif