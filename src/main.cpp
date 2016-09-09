#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "Universe.hpp"
#include "Star.hpp"
#include "Planet.hpp"
#include "Events/Dispatcher.hpp"
#include "Events/Listeners/Zoom.hpp"
#include "Events/Listeners/Move.hpp"
#include "Events/Listeners/Close.hpp"


int main(void)
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "Space");
  auto view             = window.getDefaultView();
  auto dispatcher       = Dispatcher();
  auto zoom             = Listener::Zoom(std::vector<sf::Event::EventType> {sf::Event::MouseWheelScrolled});
  auto close            = Listener::Close(std::vector<sf::Event::EventType> {sf::Event::Closed});
  auto move             = Listener::Move(std::vector<sf::Event::EventType> {
      sf::Event::MouseButtonPressed, sf::Event::MouseButtonReleased, sf::Event::MouseMoved});
  auto universe         = Universe();
  auto earth            = Planet(5.f, 1, sf::Vector2<float>(300.f, 300.f));

  earth.setFillColor(sf::Color::Blue);
  universe.addObject(earth);

  window.setFramerateLimit(60);

  dispatcher.registerListener(zoom);
  dispatcher.registerListener(close);
  dispatcher.registerListener(move);


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

  while (window.isOpen())
    {
      sf::Event event;

      while (window.pollEvent(event))
        {
          dispatcher.dispatch(event, view, window, universe);
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
      universe.update();
      window.draw(universe);


      window.setView(window.getDefaultView());
      window.draw(fps);
      window.display();
    }

  return 0;
}
