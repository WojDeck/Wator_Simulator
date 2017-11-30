#include <SFML/Graphics.hpp>

int n;
int x;
int y;
int main()
{

 sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
  
    window.setFramerateLimit(30);

    srand(time(0));

    sf::Texture shark;
    shark.loadFromFile("image.png");
    std::vector<sf::Sprite> Fishes(n,sf::Sprite(shark));
    for (int i = 0; i < Fishes.size(); i++){
        Fishes[n].setOrigin(15, 15);
        Fishes[n].getPosition();
        Fishes[n].setPosition(x = rand() % 790 + 10, y = rand() % -10 - 50);
    }

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
      sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
	  if (event.type == sf::Event::Closed){
                window.close();
            }

	    Fishes[n].setPosition(x, y+=1);
            Fishes[n].rotate(1);

            // clear the window with black color
            window.clear(sf::Color::Black);

            // draw everything here...
            // window.draw(...);
            window.draw(Fishes[n]);

            // end the current frame
            window.display();
        }

        return 0;
    }
}
