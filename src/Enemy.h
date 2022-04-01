#ifndef ENEMY_H
#define ENEMY_H
#include "GameManager.h"
#include <iostream>
#include <Godot.hpp>
#include <Sprite.hpp>
#include <Texture.hpp>
#include <Control.hpp>
#include <Viewport.hpp>
#include <RandomNumberGenerator.hpp>
#include <Label.hpp>

using namespace godot;

class Enemy : public Node2D {
    GODOT_CLASS(Enemy, Node2D)

public:
    Enemy();
    ~Enemy();
    Enemy(const Enemy& other);
    void Move(float delta);
    void BorderCheck();
    void RandomizeStart();

    static void _register_methods();
    void _init();

    void _ready();
    void _process(float delta);
    void _physics_process(float delta);

private:
    Vector2 position;
    float velocityX;
    float velocityY;
    float frictionCoef = 0.6f;
    float mass = 1.0f;
    float moveSpeed = 0.0f;
    float fallSpeed = 0.0f;
    float maxMoveSpeed = 25.0f;
    float minFallSpeed = 5.0f;
    float maxFallSpeed = 25.0f;
    float bottomOffset = 25.0f;
    float minSpeed = 0.1f;
    RandomNumberGenerator* random;
    bool firstFrame = true;
};

#endif