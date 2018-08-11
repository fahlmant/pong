#include "paddle.h"

Paddle::Paddle(float startX, float startY){
    
    position.x = startX;
    position.y = startY;

    batSpeed = .3f;

    batShape.setSize(sf::Vector2f(10, 100));
    batShape.setPosition(position);
}

FloatRect Bat::getPosition(){

    return batShape.getGlobalBounds();
}

RectangleShape Bat::getShape(){

    return batShape;
}

void Bat::moveLeft(){

    position.x -= batSpeed;
}

void Bat::moveRight(){

    position.x += batSpeed;
}

void Bat::update(){
    batShape.setPosition(position);
}


