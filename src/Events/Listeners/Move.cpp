#include "Universe.hpp"
#include "Move.hpp"

Listener::Move::Move(const std::vector<sf::Event::EventType> &eventTypes) : IListener(eventTypes)
{
  _isMoving = false;
}

void Listener::Move::onEvent(const sf::Event &event, sf::View &view, sf::RenderWindow &window, Universe &universe)
{
  if (event.type == sf::Event::MouseButtonPressed)
    {
      auto mousePosition = sf::Vector2<int>(event.mouseButton.x, event.mouseButton.y);
      auto objectPosition = sf::Vector2<float>(window.mapPixelToCoords(mousePosition, view));

      if (event.mouseButton.button == sf::Mouse::Right)
        {
          _isMoving = true;
          _movingFrom = objectPosition;
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
      auto mousePosition = sf::Vector2<int>(event.mouseMove.x, event.mouseMove.y);
      auto objectPosition = sf::Vector2<float>(window.mapPixelToCoords(mousePosition, view));

      // std::cout << mousePosition.x << ":" << mousePosition.y << ", "
      //           << objectPosition.y << ":" << objectPosition.y << std::endl;

      if (_isMoving)
        {
          view.move(_movingFrom - objectPosition);
          _movingFrom = objectPosition;
        }
    }
}
