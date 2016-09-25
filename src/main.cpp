#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Universe.hpp"
#include "Star.hpp"
#include "Planet.hpp"
#include "HUD.hpp"
#include "FPS.hpp"
#include "Dispatcher.hpp"
#include "Zoom.hpp"
#include "Move.hpp"
#include "Close.hpp"
#include "CreatePlanet.hpp"
#include "UniverseSpeed.hpp"
#include "MoveObject.hpp"
#include "InfoPanel.hpp"


int main(void)
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "Space");
  auto view             = window.getDefaultView();
  auto dispatcher       = Dispatcher();
  auto zoom             = Listener::Zoom(std::vector<sf::Event::EventType> { sf::Event::MouseWheelScrolled });
  auto close            = Listener::Close(std::vector<sf::Event::EventType> { sf::Event::Closed });
  auto move             = Listener::Move(std::vector<sf::Event::EventType> {
      sf::Event::MouseButtonPressed, sf::Event::MouseButtonReleased, sf::Event::MouseMoved });
  auto createPlanet     = Listener::CreatePlanet(std::vector<sf::Event::EventType> { sf::Event::MouseButtonPressed });
  auto moveObject       = Listener::MoveObject(std::vector<sf::Event::EventType> {
      sf::Event::MouseButtonPressed, sf::Event::MouseButtonReleased, sf::Event::MouseMoved });
  auto universeSpeed    = Listener::UniverseSpeed(std::vector<sf::Event::EventType> { sf::Event::KeyPressed });
  auto universe         = Universe();
  auto earth            = Planet(5.f, 1000000000, sf::Vector2<float>(300.f, 300.f));
  auto elapsedTime      = 0.f;
  auto hud              = HUD();
  auto fps              = FPS();
  auto infoPanel        = InfoPanel();

  hud.addObject(&fps);
  hud.addObject(&infoPanel);

  earth.setFillColor(sf::Color::Blue);
  universe.addObject(earth);

  window.setFramerateLimit(60);

  dispatcher.registerListener(zoom);
  dispatcher.registerListener(close);
  dispatcher.registerListener(move);
  dispatcher.registerListener(createPlanet);
  dispatcher.registerListener(moveObject);
  dispatcher.registerListener(universeSpeed);

  sf::Clock clock;

  while (window.isOpen())
    {
      sf::Event event;

      while (window.pollEvent(event))
        {
          dispatcher.dispatch(event, view, window, universe);
        }

      /* Compute elpasedTime since last frame */
      elapsedTime = clock.getElapsedTime().asSeconds();
      clock.restart();

      window.clear();

      /* Update & draw universe */
      window.setView(view);
      universe.update(elapsedTime, window, view);
      window.draw(universe);

      /* Update and draw HUD */
      window.setView(window.getDefaultView());
      hud.update(elapsedTime, window, view, universe);
      window.draw(hud);

      window.display();
    }

  return 0;
}
