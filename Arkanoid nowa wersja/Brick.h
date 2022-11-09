#pragma once
#include "Rectangle.h"
#include "Stale.h"
class Brick :
    public Rectangle, public Stale
{
public:
    bool Zniszczony;
    Brick(float bX, float bY, int a);
    void SetKolor(int a);
    Brick& operator =(const Brick& a);

};

