#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "Star.hpp"
#include "Planet.hpp"
#include "Events/Dispatcher.hpp"
#include "Events/Listeners/Zoom.hpp"
#include "Events/Listeners/Move.hpp"
#include "Events/Listeners/Close.hpp"


int main(void)
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "Space");
  auto view = window.getDefaultView();
  auto dispatcher = Dispatcher();
  auto zoom = Listener::Zoom(std::vector<sf::Event::EventType> {sf::Event::MouseWheelScrolled});
  auto close = Listener::Close(std::vector<sf::Event::EventType> {sf::Event::Closed});
  auto move = Listener::Move(std::vector<sf::Event::EventType> {
      sf::Event::MouseButtonPressed, sf::Event::MouseButtonReleased, sf::Event::MouseMoved});

  dispatcher.registerListener(zoom);
  dispatcher.registerListener(close);
  dispatcher.registerListener(move);

  window.setFramerateLimit(60);

  // TODO : Implement universe abstraction
  // TODO : Implement dynamic spaceobject creation
  std::vector<SpaceObject> objects = {Star(20.f, 3000000, sf::Vector2<float>(400.f, 400.f)),
                                      Planet(5.f, 1, sf::Vector2<float>(300.f, 300.f)),
                                      Planet(10.f, 1, sf::Vector2<float>(210.f, 350.f))};

  objects[0].setFillColor(sf::Color::Yellow);
  objects[1].setFillColor(sf::Color::Blue);
  objects[1].setSpeed(sf::Vector2<float>(0.003, -0.003));
  objects[2].setFillColor(sf::Color::Green);
  objects[2].setSpeed(sf::Vector2<float>(0.003, 0.003));

  // TODO : Implement HUD abstraction
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
          dispatcher.dispatch(event, view, window);
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
