#include "Vector2.h"

Vector2::Vector2(float Tx, float Ty) {
    x = Tx;
    y = Ty;
    beginX = Tx;
    beginY = Ty;
}

Vector2::Vector2(Vector2* v2) {
    x = v2->GetX();
    y = v2->GetY();
    beginX = v2->GetX();
    beginY = v2->GetY();
}

Vector2::~Vector2() {

}

Vector2 Vector2::operator*(const int& i) const {
    Vector2 newVector = new Vector2(0, 0);
    newVector.x = x * i;
    newVector.y = y * i;
    return newVector;
}
Vector2 Vector2::operator/(const int& i) const {
    Vector2 newVector = new Vector2(0, 0);
    newVector.x = x - i;
    newVector.y = y - i;
    return newVector;
}

Vector2& Vector2::operator+=(const Vector2& v2) {
    x = x + v2.x;
    y = y + v2.y;
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& v2) {
    x = x - v2.x;
    y = y - v2.y;
    return *this;
}

Vector2 Vector2::operator+(const Vector2& v2) const {
    Vector2 newVector = new Vector2(0, 0);
    newVector.x = x + v2.x;
    newVector.y = y + v2.y;
    return newVector;
}

Vector2 Vector2::operator-(const Vector2& v2) const {
    Vector2 newVector = new Vector2(0, 0);
    newVector.x = x - v2.x;
    newVector.y = y - v2.y;
    return newVector;
}

bool Vector2::operator<(const int& i) {
    if(x+y < i){
        return true;
    }else {
        return false;
    }
}

bool Vector2::operator>(const int& i) {
    if(x+y > i){
        return true;
    }else{
        return false;
    }
}

bool Vector2::operator==(const Vector2& i) {
    if(i.x == x && i.y == y){
        return true;
    }else{
        return false;
    }
}

bool Vector2::operator!=(const Vector2& i) {
    if(i.x == x && i.y == y){
        return false;
    }else{
        return true;
    }
}

float Vector2::Magnitude() {
    float Mx = beginX - x;
    float My = beginY - y;
    float magn = sqrt(std::pow(Mx, 2) + std::pow(My, 2));
    magnitude = magn;
    return magn;
}

float Vector2::Angle() {
    float Mx = beginX - x;
    float My = beginY - y;
    float angle = tan(My/Mx);
    return angle;
}

float Vector2::Distance(Vector2 other, float sizeSelf, float sizeOther) {
    float Mx = x - other.GetX();
    float My = y - other.GetY();
    float dir = sqrt(std::pow(Mx, 2) + std::pow(My, 2));
    float dist = dir - sizeSelf - sizeOther;
    return dist;
}

Vector2& Vector2::Normalize() {
    x = x / magnitude;
    y = y / magnitude;
    return *this;
}

//Getters
float Vector2::GetX() {
    return x;
}

float Vector2::GetY() {
    return y;
}