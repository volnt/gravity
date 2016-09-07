#include "Listener.hpp"

const std::vector<sf::Event::EventType> &Listener::getEventTypes() const
{
  return (_eventTypes);
}
