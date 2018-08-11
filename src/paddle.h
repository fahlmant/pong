#include<SFML/Graphics.hpp>

using namespace sf;

class Paddle {

    private:
        Vector2f position;
        RectangleShape paddleShape;
    public:
        Paddle(float startX, float startY);
        FloatRect getPosition();
        RectangleShape getShape();
        void moveUp();
        void moveDown();
        void update();
};
