#include <iostream>
#include <iterator>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "Star.hpp"
#include "Planet.hpp"

int main(void)
{
  sf::RenderWindow window(sf::VideoMode(200, 200), "Space");

  std::vector<SpaceObject> objects = {Star(20.f, 3000000, sf::Vector2<float>(150.f, 10.f)),
                                      Planet(5.f, 50, sf::Vector2<float>(10.f, 10.f)),
                                      Planet(10.f, 2000000, sf::Vector2<float>(10.f, 150.f))};

  objects[0].setFillColor(sf::Color::Yellow);
  objects[1].setFillColor(sf::Color::Blue);
  objects[2].setFillColor(sf::Color::Green);

  while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
        {
          if (event.type == sf::Event::Closed)
            window.close();
        }

      window.clear();

      for (size_t i = 0; i < objects.size(); i++)
        {
          if (objects[i].getExists())
            {
              objects[i].collide(objects);
              objects[i].move(objects[i].getGravitationalForce(objects) * 1000.f);
              window.draw(objects[i]);
            }
        }

      window.display();
    }

  return 0;
}
