#ifndef COLLISION_H
#define COLLISION_H
#include <iostream>
#include <Godot.hpp>
#include <Control.hpp>
#include <Node2D.hpp>
#include <string.hpp>
#include <KinematicBody2D.hpp>

using namespace godot;

class Collision : public KinematicBody2D{
    GODOT_CLASS(Collision, KinematicBody2D)

    public:
    Collision();
    ~Collision();

    static void _register_methods();
    void _init();

    void _ready();
    void _process(float delta);
    void _physics_process(float delta);

    private:

};

#endif