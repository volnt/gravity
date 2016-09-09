#include <iostream>
#include "IListener.hpp"

IListener::IListener(const std::vector<sf::Event::EventType> &eventTypes)
{
  _eventTypes = eventTypes;
}

IListener::~IListener()
{
}

const std::vector<sf::Event::EventType> &IListener::getEventTypes() const
{
  return (_eventTypes);
}
