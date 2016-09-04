#include <SFML/Graphics.hpp>

#include "Star.hpp"
#include "Planet.hpp"

int main(void)
{
  sf::RenderWindow window(sf::VideoMode(200, 200), "Space");

  Star star = Star(20.f);
  Planet earth = Planet(3.f);

  star.setPosition(10.f, 10.f);
  earth.setPosition(10.f, 10.f);

  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
        {
          if (event.type == sf::Event::Closed)
            window.close();
        }

      window.clear();
      window.draw(shape);
      window.display();
    }

  return 0;
}
