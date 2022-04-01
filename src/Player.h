#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <Godot.hpp>
#include <Node2D.hpp>
#include <Viewport.hpp>
#include <Input.hpp>
#include <Area2D.hpp>
#include <Variant.hpp>

using namespace godot;

class Player : public Node2D {
    GODOT_CLASS(Player, Node2D)

public:
    Player();
    ~Player();

    static void _register_methods();
    void _init();

    void _ready();
    void _process(float delta);
    void _physics_process(float delta);
    void area_entered(Area2D *body);

private:
    void Move(float delta);
    void borderCheck();

    Vector2 position;
    float velocity;
    float frictionCoef = 0.6f;
    float mass = 1.0f;
    float moveSpeed = 5.0f;
    Input* input;
};

#endif