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
  auto createPlanet     = Listener::CreatePlanet(std::vector<sf::Event::EventType> {
      sf::Event::MouseButtonPressed, sf::Event::MouseButtonReleased, sf::Event::MouseMoved });
  auto moveObject       = Listener::MoveObject(std::vector<sf::Event::EventType> {
      sf::Event::MouseButtonPressed, sf::Event::MouseButtonReleased, sf::Event::MouseMoved });
  auto universeSpeed    = Listener::UniverseSpeed(std::vector<sf::Event::EventType> { sf::Event::KeyPressed });
  auto universe         = Universe();
  auto sun              = Star(20.f, 1000000000, sf::Vector2<float>(400.f, 400.f));
  auto earth            = Planet(6.f, 2, sf::Vector2<float>(200.f, 400.f));
  auto mars             = Planet(4.f, 1, sf::Vector2<float>(600.f, 400.f));
  auto elapsedTime      = 0.f;
  auto hud              = HUD();
  auto fps              = FPS();
  auto infoPanel        = InfoPanel();

  hud.addObject(&fps);
  hud.addObject(&infoPanel);

  earth.setSpeed(sf::Vector2<float>(0.f, -0.01));
  earth.setFillColor(sf::Color::Blue);
  mars.setSpeed(sf::Vector2<float>(0.f, -0.02));
  mars.setFillColor(sf::Color::Red);
  sun.setFillColor(sf::Color::Yellow);
  universe.addObject(&sun);
  universe.addObject(&earth);
  universe.addObject(&mars);

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
