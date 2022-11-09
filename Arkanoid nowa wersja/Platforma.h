#pragma once
#include <SFML/Graphics.hpp>
#include "Rectangle.h"
#include "Stale.h"

class Platforma :
    public Rectangle
{
public:
    Stale stala;
    sf::Vector2f velocity;

    Platforma(float mX, float mY);
    void update();
    void Reset();
    void avc();
};

