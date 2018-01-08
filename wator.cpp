#include <SFML/Graphics.hpp>
const int Fish_Number = 50;
const int Fish = 1;
const int Shark_Number = 25;
const int Fish_Breed = 10;
const int Shark_Breed = 10;
const int Shark_Starve = -1;
const int starve = 20;
const int water = 0;
const int Water_Width = 160;
const int Water_Height = 160;
int x, y;
int WATER[Water_Width][Water_Height];


 sf::RenderWindow window(sf::VideoMode(800, 800), "Wator Simulator!");
sf::RectangleShape OceanRec;
OceanRec.setSize(sf::Vector2F(5,5));
OceanRec.setFillColor(sf::Color::Blue);

/*
 *spawn a fish a at random position
 *
 */
void addFish() {
    for (int i = 0; i < Fish_Number; ++i) {
        y = rand() % Water_Width;
        x = rand() % Water_Height;
        water[y][x] = Fish;
        Rec[Water_Width*y+x].setFillColor(sf::Color::Green);
    }
}
void drawOcean()
{
    // draw the Cells
    for (int i = 0; i < Water_Width*Water_Height; ++i)
    {
        window.draw(OceanRec[i]);
    }
}
int main(){
  


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

            window.clear(sf::Color::Black);

            // draw everything here...
            // window.draw(...);
	    drawOcean();
	    addFish();
            //window.draw();

            // end the current frame
            window.display();
        }

        return 0;
    }
}
