#include <iostream>
#include <iterator>
#include <string>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "Star.hpp"
#include "Planet.hpp"

int main(void)
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "Space");
  sf::View view = window.getDefaultView();

  window.setFramerateLimit(60);

  std::vector<SpaceObject> objects = {Star(20.f, 3000000, sf::Vector2<float>(400.f, 400.f)),
                                      Planet(5.f, 1, sf::Vector2<float>(300.f, 300.f)),
                                      Planet(10.f, 1, sf::Vector2<float>(210.f, 350.f))};

  objects[0].setFillColor(sf::Color::Yellow);
  objects[1].setFillColor(sf::Color::Blue);
  objects[1].setSpeed(sf::Vector2<float>(0.003, -0.003));
  objects[2].setFillColor(sf::Color::Green);
  objects[2].setSpeed(sf::Vector2<float>(0.003, 0.003));

  sf::Clock clock;
  sf::Text fps;
  sf::Font font;
  font.loadFromFile("VCR_OSD_Mono.ttf");
  fps.setFont(font);
  fps.setString("hello");
  fps.setPosition(20, 20);
  fps.setColor(sf::Color::White);
  fps.setCharacterSize(10);

  float elapsedTime = 0;
  int frames = 0;
  bool movingView = false;
  sf::Vector2<float> movingFrom;

  while (window.isOpen())
    {
      sf::Event event;

      while (window.pollEvent(event))
        {
          if (event.type == sf::Event::Closed)
            window.close();
          else if (event.type == sf::Event::MouseWheelScrolled)
            {
              view.zoom(1 - event.mouseWheelScroll.delta / 10.f);
            }
          else if (event.type == sf::Event::MouseButtonPressed)
            {
              if (event.mouseButton.button == sf::Mouse::Left)
                {
                  movingView = true;
                  movingFrom.x = event.mouseButton.x;
                  movingFrom.y = event.mouseButton.y;
                }
            }
          else if (event.type == sf::Event::MouseButtonReleased)
            {
              if (event.mouseButton.button == sf::Mouse::Left)
                movingView = false;
            }
          else if (event.type == sf::Event::MouseMoved)
            {
              if (movingView)
                {
                  view.move(movingFrom - sf::Vector2<float>(event.mouseMove.x, event.mouseMove.y));
                  movingFrom.x = event.mouseMove.x;
                  movingFrom.y = event.mouseMove.y;
                }
            }

        }

      elapsedTime = clock.getElapsedTime().asSeconds();

      if (elapsedTime > 1)
        {
          fps.setString(std::to_string(frames) + " fps");
          frames = 0;
          clock.restart();
        }
      else
        {
          frames += 1;
        }

      window.clear();

      window.setView(view);
      for (size_t i = 0; i < objects.size(); i++)
        {
          if (objects[i].getExists())
            {
              objects[i].collide(objects);
              objects[i].setSpeed(objects[i].getSpeed() + objects[i].getGravitationalForce(objects));
              objects[i].move(objects[i].getSpeed() * 10.f);
              window.draw(objects[i]);
            }
        }
      window.setView(window.getDefaultView());
      window.draw(fps);
      window.display();
    }

  return 0;
}
