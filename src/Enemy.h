#pragma once
#include <iostream>
#include "Vector2.h"
#include <Control.hpp>
#include <RigidBody2D.hpp>

using namespace godot;

class Enemy : public RigidBody2D{
    public:
        Enemy(int windowW);
        ~Enemy();
        void Move(float dt);
        //sf::CircleShape Draw(float dt);
        void BorderCheck();
        ::Vector2* position;
        float velocityX;
        float velocityY;
        float frictionCoef = 0.6;
        float mass = 1;
        int enimSize = 10;

    private:
        int wW;
        float posX = rand() % 800;
        float posY = -10;
        float moveSpeed = rand() % 25;
        float fallSpeed = rand() % 25;
        float minSpeed = 10;
        //sf::CircleShape shape;
};