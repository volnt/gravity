#include <SFML/Graphics.hpp>

#include "Universe.hpp"
#include "Planet.hpp"
#include "CreatePlanet.hpp"

Listener::CreatePlanet::CreatePlanet(const std::vector<sf::Event::EventType> &eventTypes) : IListener(eventTypes)
{
  _movingObject = NULL;
  _speedLine = NULL;
}

void Listener::CreatePlanet::onEvent(const sf::Event &event, sf::View &view, sf::RenderWindow &window, Universe &universe)
{
  if (event.type == sf::Event::MouseButtonPressed)
    {
      if (event.mouseButton.button == sf::Mouse::Left)
        {
          if (!universe.getObjectAtCursor())
            {
              auto mousePosition = sf::Vector2<int>(event.mouseButton.x, event.mouseButton.y);
              auto planetPosition = sf::Vector2<float>(window.mapPixelToCoords(mousePosition, view));

              auto *planet = new Planet(10.f, 1, planetPosition);
              planet->setFillColor(sf::Color::Blue);
              _movingObject = planet;

              auto *line = new sf::VertexArray(sf::Lines, 2);
              (*line)[0].position = planetPosition;
              (*line)[1].position = planetPosition;
              _speedLine = line;
              universe.addOverlay(_speedLine);
            }
        }
    }
  else if (event.type == sf::Event::MouseButtonReleased)
    {
      if (event.mouseButton.button == sf::Mouse::Left)
        {
          universe.addObject(_movingObject);
          _movingObject = NULL;
          universe.removeOverlay(_speedLine);
          _speedLine = NULL;
        }
    }
  else if (event.type == sf::Event::MouseMoved)
    {
      auto mousePosition = sf::Vector2<int>(event.mouseMove.x, event.mouseMove.y);
      auto objectPosition = sf::Vector2<float>(window.mapPixelToCoords(mousePosition, view));

      if (_movingObject)
        {
          (*_speedLine)[1].position = objectPosition;
          _movingObject->setSpeed((objectPosition - _movingObject->getPosition()) / 1000.f);
        }
    }
}
