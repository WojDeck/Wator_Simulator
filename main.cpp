/*! 
      @author: Wojciech Teodorowicz
@date created: 13/11/17
     @version: 0.9
 @lastUpdated: 13/11/17
     @purpose: Wator Simulation using SFML Graphics
 */

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

const int Shark_Num = 100;
const int Fish_Num = 200;
unsigned int width = 800;
unsigned int height = 800;
const int Circle = 400;

void animationSequence ( RenderWindow& window, CircleShape& circle, float x, float y ) {

        window.clear(Color(255,255,255,255));           // Fill the window with even white colour
        circle.setPosition(x, y);               // Update position of circle in window
        window.draw(circle);            // Draw circle in rendered window
        window.display();                       // Display on screeen what has been rendered to the window so far

}

int main(void)
{	
	
    sf::RenderWindow window(sf::VideoMode(width, height), "Wator Simulation");
    std::vector<std::vector< sf::CircleShape>> Shape(Circle)
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(Shape);
        window.display();
    }

    return 0;
}
