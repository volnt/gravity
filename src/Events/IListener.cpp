#include "IListener.hpp"

IListener::IListener(const std::vector<sf::Event::EventType> &eventTypes)
{
  _eventTypes = eventTypes;
}

IListener::~IListener()
{
}

const sf::Vector2<float> IListener::pixelToCoord(const sf::Vector2<int> &position, const sf::RenderWindow &window, const sf::View &view) const
{
  return sf::Vector2<float>(window.mapPixelToCoords(sf::Vector2<int>(position.x, position.y), view));
}

const sf::Vector2<float> IListener::pixelToCoord(const sf::Vector2<float> &position, const sf::RenderWindow &window, const sf::View &view) const
{
  return sf::Vector2<float>(window.mapPixelToCoords(sf::Vector2<int>(position.x, position.y), view));
}

const std::vector<sf::Event::EventType> &IListener::getEventTypes() const
{
  return (_eventTypes);
}
