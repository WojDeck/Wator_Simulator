#include <SFML/Graphics.hpp>



int main()
{
  int NumShark = 5;
  int NumFish = 10;
  int x;
  int y;

  sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
  // Set Frame Rate to 60fps
  srand(time(0));
    window.setFramerateLimit(60);
    sf::CircleShape shark(5);
    shark.setFillColor(sf::Color(sf::Color::Red));
    sf::CircleShape fish(1);
    fish.setFillColor(sf::Color(sf::Color::Blue));
    std::vector<sf::CircleShape> Sharks(NumShark,sf::CircleShape(shark));

      for (NumShark = 0; i < Sharks.size(); NumShark++)
	{
	Sharks[NumShark].setOrigin(15, 15);
        Sharks[NumShark].getPosition();
        Sharks[NumShark].setPosition(x = rand() % 790 + 10, y = rand() % -10 - 50);
    }
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
      sf::Event event;
        while (window.pollEvent(event))
	  {
            // "close requested" event: we close the window
	  if (event.type == sf::Event::Closed)
                window.close();
        }

	    Sharks[NumShark].setPosition(x, y+=1);
            Sharks[NumShark].rotate(1);

            // clear the window with black color
            window.clear(sf::Color::Black);

            // draw everything here...
            // window.draw(...);
            window.draw(Sharks(NumShark);

            // end the current frame
            window.display();
        }

        return 0;
}
