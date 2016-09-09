#include "Move.hpp"

Listener::Move::Move(const std::vector<sf::Event::EventType> &eventTypes) : IListener(eventTypes)
{
  _isMoving = false;
}

void Listener::Move::onEvent(const sf::Event &event, sf::View &view, sf::RenderWindow &window)
{
  if (event.type == sf::Event::MouseButtonPressed)
    {
      if (event.mouseButton.button == sf::Mouse::Right)
        {
          _isMoving = true;
          _movingFrom.x = event.mouseButton.x;
          _movingFrom.y = event.mouseButton.y;
        }
    }
  else if (event.type == sf::Event::MouseButtonReleased)
    {
      if (event.mouseButton.button == sf::Mouse::Right)
        {
          _isMoving = false;
        }
    }
  else if (event.type == sf::Event::MouseMoved)
    {
      if (_isMoving)
        {
          view.move(_movingFrom - sf::Vector2<float>(event.mouseMove.x, event.mouseMove.y));
          _movingFrom.x = event.mouseMove.x;
          _movingFrom.y = event.mouseMove.y;
        }
    }
}
