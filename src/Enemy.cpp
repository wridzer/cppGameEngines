#include "Enemy.h"

void Enemy::_register_methods(){
    register_method("_ready", &Enemy::_ready);
    register_method("_process", &Enemy::_process);
    register_method("_physics_process", &Enemy::_physics_process);

    register_property("moveSpeed", &Enemy::maxMoveSpeed, 25.0f);
    register_property("fallSpeed", &Enemy::maxFallSpeed, 25.0f);
    register_property("minfallSpeed", &Enemy::minFallSpeed, 25.0f);
    register_property("bottomOffset", &Enemy::bottomOffset, 50.0f);
}

Enemy::Enemy() 
: velocityX(.0f), velocityY(.0f), mass(1.0f), frictionCoef(.6f), firstFrame(true)
{

}

Enemy::~Enemy() {

}

void Enemy::_init(){

}

void Enemy::_ready(){
    random = RandomNumberGenerator::_new();
    RandomizeStart();
}

void Enemy::_process(float delta){
    set_position(position);
}

void Enemy::_physics_process(float delta){
    Move(delta);
}

void Enemy::Move(float delta) {
    float accelerationX = 0.0f;
    float accelerationY = 0.0f;
    
    accelerationX += moveSpeed * delta;
    accelerationY += fallSpeed * delta;

    velocityX = (1.0f/frictionCoef) * (std::pow(2.71828f,-frictionCoef/mass*delta))*(frictionCoef*velocityX+mass*accelerationX)-(mass*accelerationX/frictionCoef);
    velocityY = (1.0f/frictionCoef) * (std::pow(2.71828f,-frictionCoef/mass*delta))*(frictionCoef*velocityY+mass*accelerationY)-(mass*accelerationY/frictionCoef);
    
    Vector2 move = Vector2(velocityX,-velocityY);
    position = position + move;
    BorderCheck();
}

void Enemy::BorderCheck() {
    if (position.x > get_viewport()->get_size().x)
    {
        velocityX = velocityX *-1;
        moveSpeed = moveSpeed *-1;
    }
    if (position.x < 0.f)
    {
        velocityX = velocityX *-1;
        moveSpeed = moveSpeed *-1;
    }
}

void Enemy::RandomizeStart(){
    random->randomize();

    position = Vector2(random->randf_range(0.0f, get_viewport()->get_size().x), -10.0f);
    set_position(position);

    fallSpeed = random->randf_range(minFallSpeed, maxFallSpeed);
    moveSpeed = random->randf_range(0.1f, maxMoveSpeed);
}