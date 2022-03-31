#include "Player.h"

void Player::_register_methods(){
    register_method("_ready", &Player::_ready);
    register_method("_process", &Player::_process);
    register_method("_physics_process", &Player::_physics_process);
    register_method("area_entered", &Player::area_entered);

    register_signal<Player>("hit", Dictionary());

    register_property("moveSpeed", &Player::moveSpeed, 5.0f);
}

Player::Player() 
: velocity(.0f), mass(1.0f), frictionCoef(.6f)
{

}

Player::~Player() {

}

void Player::_init(){
}

void Player::_ready(){
    position = get_position();
}

void Player::area_entered(Area2D *area){
    emit_signal("hit", area);
}

void Player::_process(float delta){
    set_position(position);
}

void Player::_physics_process(float delta){
    input = Input::get_singleton();
    Move(delta);


}

void Player::Move(float delta){
    float acceleration = 0.0f;
    if (input->is_action_pressed("move_left"))
    {
        acceleration += moveSpeed * delta;
    }
    if (input->is_action_pressed("move_right"))
    {
        acceleration += -moveSpeed * delta;
    }
    //velocity = (1/drag coefficient) * (e^-dragC/m*ΔT)*(dragC*velocity+mass*a)-(mass*a/dragC)
    velocity = (1.0f/frictionCoef) * (std::pow(2.71828f,-frictionCoef/mass*delta))*(frictionCoef*velocity+mass*acceleration)-(mass*acceleration/frictionCoef);
    Vector2 move = Vector2(velocity, 0.0f);
    position = position + move;
    borderCheck();
}

void Player::borderCheck() {
    if (position.x > get_viewport()->get_size().x)
    {
        position = position + Vector2(-get_viewport()->get_size().x, 0);
    }
    if (position.x < (0.f - get_scale().x * 2))
    {
        position = position + Vector2(get_viewport()->get_size().x, 0);
    }
}