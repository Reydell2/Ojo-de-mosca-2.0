#include <SFML/Graphics.hpp>
#include <cmath>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int RADIUS = 150;

void drawFlyEye(sf::RenderWindow& window) {

    sf::CircleShape circle(RADIUS);
    circle.setPosition(SCREEN_WIDTH / 2 - RADIUS, SCREEN_HEIGHT / 2 - RADIUS);

    window.draw(circle);

   
    int numPoints = 16;
    sf::VertexArray curve(sf::Lines, numPoints * (numPoints - 1) * 2); 

    int lineIndex = 0;
    for (int i = 0; i < numPoints; ++i) {
        double angle = 2.0 * 3.141516 * i / numPoints;
        float x1 = SCREEN_WIDTH / 2 + RADIUS * cos(angle);
        float y1 = SCREEN_HEIGHT / 2 + RADIUS * sin(angle);

        for (int j = 0; j < numPoints; ++j) {
            if (j != i) {
                double angle2 = 2.0 * 3.141516 * j / numPoints;
                float x2 = SCREEN_WIDTH / 2 + RADIUS * cos(angle2);
                float y2 = SCREEN_HEIGHT / 2 + RADIUS * sin(angle2);

                curve[lineIndex].position = sf::Vector2f(x1, y1);
                curve[lineIndex].color = sf::Color::Green;
                ++lineIndex;

                curve[lineIndex].position = sf::Vector2f(x2, y2);
                curve[lineIndex].color = sf::Color::Red;
                ++lineIndex;
            }
        }
    }

    window.draw(curve);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Fly Eye");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);

        drawFlyEye(window);

        window.display();
    }

    return 0;
}












