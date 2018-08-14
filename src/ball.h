#include <SFML/Graphics.hpp>
using namespace sf;

class Ball {

    private:
        Vector2f position;
        RectangleShape ballShape;
        float xVel;
        float yVel;

    public:
        Ball(float startX, float startY);
        FloatRect getPosition();
        RectangleShape getShape();
        float getXVel();
        float getYVel();
        void reboundTopBottom();
        void reboundPaddles();
        void hitGoal(int x, int y);
        void update();

};
