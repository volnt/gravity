#include <iostream>
#include <SFML/Graphics.hpp>

#include "Universe.hpp"
#include "Planet.hpp"
#include "MoveObject.hpp"

Listener::MoveObject::MoveObject(const std::vector<sf::Event::EventType> &eventTypes) : IListener(eventTypes)
{
  _movingObject = NULL;
}

void Listener::MoveObject::onEvent(const sf::Event &event, sf::View &view, sf::RenderWindow &window, Universe &universe)
{
  if (event.type == sf::Event::MouseButtonPressed)
    {
      if (event.mouseButton.button == sf::Mouse::Left)
        {
          auto *object = universe.getObjectAtCursor();
          if (object)
            {
              _movingObject = object;
            }
        }
    }
  else if (event.type == sf::Event::MouseButtonReleased)
    {
      if (event.mouseButton.button == sf::Mouse::Left)
        {
          _movingObject = NULL;
        }
    }
  else if (event.type == sf::Event::MouseMoved)
    {
      auto mousePosition = sf::Vector2<int>(event.mouseMove.x, event.mouseMove.y);
      auto objectPosition = sf::Vector2<float>(window.mapPixelToCoords(mousePosition, view));

      if (_movingObject)
        {
          _movingObject->setPosition(objectPosition);
        }
    }
}
