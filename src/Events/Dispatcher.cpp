#include <iostream>
#include "Dispatcher.hpp"

void Dispatcher::registerListener(Listener &listener)
{
  for (auto eventType: listener.getEventTypes())
    {
      if (_listeners.find(eventType) == _listeners.end())
        {
          _listeners[eventType] = std::vector<Listener*>();
        }
      std::cout << "Registering listener with eventType " << eventType << std::endl;
      _listeners[eventType].push_back(&listener);
    }
}

void Dispatcher::dispatch(const sf::Event &event, sf::View &view, sf::RenderWindow &window)
{
  if (_listeners.find(event.type) != _listeners.end())
    {
      for (auto &listener: _listeners.find(event.type)->second)
        {
          std::cout << "Sending event" << std::endl;
          listener->onEvent(event, view, window);
        }
    }
}
