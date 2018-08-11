#include<SFML/Graphics.hpp>

using namespace sf;

class Paddle {

    private:
        Vector2f position;
        RectangleShape batShape;
        float batSpeed;

    public:
        Paddle(float startX, float startY);
        FloatRect getPosition();
        RectangleShape getShape();
        void moveLeft();
        void moveRight();
        void update();
};
