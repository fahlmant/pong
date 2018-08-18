#include "ball.h"

Ball::Ball(float startX, float startY){

    position.x = startX;
    position.y = startY;

    xVel = .05f;
    yVel = .05f;

    ballShape.setSize(sf::Vector2f(10, 10));
    ballShape.setPosition(position);
}

FloatRect Ball::getPosition(){

    return ballShape.getGlobalBounds();
}

RectangleShape Ball::getShape(){

    return ballShape;
}

float Ball::getXVel(){

    return xVel;
}

float Ball::getYVel(){

    return yVel;
}


void Ball::reboundTopBottom(){

    yVel = -yVel;
}

void Ball::reboundPaddles(){

    xVel = -xVel;
}

void Ball::hitGoal(int x, int y){

    ballShape.setPosition(position);
}

void Ball::update(){

    position.x += xVel;
    position.y += yVel;
    ballShape.setPosition(position);
}
