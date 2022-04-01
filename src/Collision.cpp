#include "Collision.h"

    Collision::Collision(){

    }
    Collision::~Collision(){

    }

    void Collision::_register_methods(){
    register_method("_ready", &Collision::_ready);
    register_method("_process", &Collision::_process);
    register_method("_physics_process", &Collision::_physics_process);
    }
    void Collision::_init(){

    }

    void Collision::_ready(){

    }
    void Collision::_process(float delta){

    }
    void Collision::_physics_process(float delta){
        // Vector2 velocity = move_and_slide(velocity);
        // for (int i; i < get_slide_count(); i++){
        //     auto collision = get_slide_collision(i);
        //     std::cout << "I collided with " << collision.instance().to_string() << std::endl;
        // }
    }