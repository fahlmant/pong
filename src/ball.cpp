#include "ball.h"

Ball::Ball(float startX, float startY){

    position.x = startX;
    position.y = startY;

    xVel = .03f;
    yVel = .03f;

    ballShape.setSize(sf::Vector2f(10, 10));
    ballShape.setPosition(position);
}

void Ball::hitGoal(float x, float y, float xv, float yv) {

    position.x = x;
    position.y = y;
    ballShape.setPosition(position);
    xVel = xv;
    yVel = yv;
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

void Ball::update(){

    position.x += xVel;
    position.y += yVel;
    ballShape.setPosition(position);
}
