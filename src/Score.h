#ifndef SCORE_H
#define SCORE_H

#include <Godot.hpp>
#include <iostream>
#include <Label.hpp>

using namespace godot;

class Score : public Label {
    GODOT_CLASS(Score, Label)

    public:
        Score();
        ~Score();
        static void _register_methods();
        //void _ScoreChanged(int score);
};

#endif