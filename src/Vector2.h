#pragma once
#include <cmath>

class Vector2 : {
public:
    Vector2(float Tx, float Ty);
    Vector2(Vector2* v2);
    ~Vector2();
    Vector2 operator*(const int& i) const;
    Vector2 operator/(const int& i) const;
    bool operator<(const int& i);
    bool operator>(const int& i);
    bool operator==(const Vector2& i);
    bool operator!=(const Vector2& i);
    Vector2& operator+=(const Vector2& v2);
    Vector2& operator-=(const Vector2& v2);
    Vector2 operator+(const Vector2& v2) const;
    Vector2 operator-(const Vector2& v2) const;

    float GetX();
    float GetY();

    float Magnitude();
    Vector2& Normalize();
    float Angle();
    float Distance(Vector2 other, float sizeSelf, float sizeOther);

private:
    float x;
    float y;
    float beginX;
    float beginY;
    float magnitude;
};