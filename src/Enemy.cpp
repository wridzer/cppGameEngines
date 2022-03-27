#include "Enemy.h"

void Enemy::_register_methods(){
    register_method("_process", &Enemy::_process);
    register_method("move", &Enemy::Move);
    register_property<Enemy, float>("moveSpeed", &Enemy::moveSpeed, 5);
    register_property<Enemy, float>("fallSpeed", &Enemy::fallSpeed, 5);
}

Enemy::Enemy() {

}

Enemy::~Enemy() {

}

void Enemy::_init(){
    position = Vector2(posX, posY);
}

void Enemy::_process(float delta){
    Move(delta);
    // Vector2* move = new Vector2(moveSpeed * delta, fallSpeed * delta);
    // position = position + *move;
    set_position(position);
    std::cout << position.x << ", " << position.y << std::endl;
    
}

void Enemy::Move(float delta) {
    float accelerationX = 0;
    float accelerationY = 0;

    accelerationX += moveSpeed * delta;
    accelerationY += fallSpeed * delta;

    velocityX = (1/frictionCoef) * (std::pow(2.71828f,-frictionCoef/mass*delta))*(frictionCoef*velocityX+mass*accelerationX)-(mass*accelerationX/frictionCoef);
    velocityY = (1/frictionCoef) * (std::pow(2.71828f,-frictionCoef/mass*delta))*(frictionCoef*velocityY+mass*accelerationY)-(mass*accelerationY/frictionCoef);

    Vector2* move = new Vector2(velocityX, -velocityY); 
    std::cout << velocityX << ", " << -velocityY << std::endl;
    position = position + *move;
    
    BorderCheck();
}

/*sf::CircleShape Enemy::Draw(float dt) {
    Move(dt);
    sf::CircleShape shape(enimSize);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(position->GetX(), position->GetY());
    return shape;
}*/

void Enemy::BorderCheck() {
    if (position.x > canvasWidth)
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