#include <iostream>
#include "Listener.hpp"

Listener::Listener(const std::vector<sf::Event::EventType> &eventTypes)
{
  _eventTypes = eventTypes;
}

Listener::~Listener()
{
  std::cout << "Destroying listener.." << std::endl;
}

const std::vector<sf::Event::EventType> &Listener::getEventTypes() const
{
  return (_eventTypes);
}
