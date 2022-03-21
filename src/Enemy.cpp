#include "Enemy.h"

Enemy::Enemy(int windowW) {
    wW = windowW;
    position = new ::Vector2(posX, posY);
}

Enemy::~Enemy() {

}

void Enemy::Move(float dt) {
    float accelerationX = 0;
    float accelerationY = 0;
    if (fallSpeed <= minSpeed)
    {
        fallSpeed = rand() % 50;
    }
    if (moveSpeed == 0)
    {
        moveSpeed = rand() % 50;
    }
    accelerationX += moveSpeed * dt;
    accelerationY += fallSpeed * dt;
    velocityX = (1/frictionCoef) * (std::pow(2.71828,-frictionCoef/mass*dt))*(frictionCoef*velocityX+mass*accelerationX)-(mass*accelerationX/frictionCoef);
    velocityY = (1/frictionCoef) * (std::pow(2.71828,-frictionCoef/mass*dt))*(frictionCoef*velocityY+mass*accelerationY)-(mass*accelerationY/frictionCoef);
    ::Vector2* move = new ::Vector2(velocityX,-velocityY);
    *position = *position + *move;
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
    if (position->GetX() > wW)
    {
        velocityX = velocityX *-1;
        moveSpeed = moveSpeed *-1;
    }
    if (position->GetX() < 0.f)
    {
        velocityX = velocityX *-1;
        moveSpeed = moveSpeed *-1;
    }
}