#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <Godot.hpp>
#include <Control.hpp>
#include <RigidBody2D.hpp>

using namespace godot;

class Enemy : public Node2D {
    GODOT_CLASS(Enemy, Node2D)

public:
    Enemy();
    ~Enemy();
    void Move(float delta);
    void BorderCheck();
    Vector2 position;
    float velocityX;
    float velocityY;
    float frictionCoef = 1;
    float mass = 1;
    static void _register_methods();
    void _process(float delta);
    void _init();

private:
    float posX = 550;
    float posY = -10;
    float moveSpeed = 0.005f;
    float fallSpeed = 0.003f;
    float minSpeed = 0.000001f;
    float canvasWidth = 1020;
};

#endif