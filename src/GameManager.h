#pragma once
#include <iostream>
#include <Godot.hpp>
#include <Control.hpp>

using namespace godot;

class GameManager : public Node{
    public:
        GameManager();
        ~GameManager();

        void _register_methods();
        void _process();
    private:
};