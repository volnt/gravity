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
#include "Events/Listeners/CreatePlanet.hpp"


int main(void)
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "Space");
  auto view             = window.getDefaultView();
  auto dispatcher       = Dispatcher();
  auto zoom             = Listener::Zoom(std::vector<sf::Event::EventType> {sf::Event::MouseWheelScrolled});
  auto close            = Listener::Close(std::vector<sf::Event::EventType> {sf::Event::Closed});
  auto move             = Listener::Move(std::vector<sf::Event::EventType> {
      sf::Event::MouseButtonPressed, sf::Event::MouseButtonReleased, sf::Event::MouseMoved});
  auto createPlanet     = Listener::CreatePlanet(std::vector<sf::Event::EventType> { sf::Event::MouseButtonPressed });
  auto universe         = Universe();
  auto earth            = Planet(5.f, 1, sf::Vector2<float>(300.f, 300.f));
  float elapsedTime     = 0.f;

  earth.setFillColor(sf::Color::Blue);
  universe.addObject(earth);

  window.setFramerateLimit(60);

  dispatcher.registerListener(zoom);
  dispatcher.registerListener(close);
  dispatcher.registerListener(move);
  dispatcher.registerListener(createPlanet);


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

  while (window.isOpen())
    {
      sf::Event event;

      while (window.pollEvent(event))
        {
          dispatcher.dispatch(event, view, window, universe);
        }

      elapsedTime = clock.getElapsedTime().asSeconds();
      clock.restart();

      window.clear();

      /* Update & draw universe */
      window.setView(view);
      universe.update(elapsedTime);
      window.draw(universe);

      /* Update and draw HUD */
      window.setView(window.getDefaultView());
      fps.setString(std::to_string((int)(1 / elapsedTime)) + " fps");
      window.draw(fps);

      window.display();
    }

  return 0;
}
