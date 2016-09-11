#include "Universe.hpp"
#include "Dispatcher.hpp"

void Dispatcher::registerListener(IListener &listener)
{
  for (auto eventType: listener.getEventTypes())
    {
      if (_listeners.find(eventType) == _listeners.end())
        {
          _listeners[eventType] = std::vector<IListener*>();
        }
      _listeners[eventType].push_back(&listener);
    }
}

void Dispatcher::dispatch(const sf::Event &event, sf::View &view, sf::RenderWindow &window, Universe &universe)
{
  if (_listeners.find(event.type) != _listeners.end())
    {
      for (auto &listener: _listeners.find(event.type)->second)
        {
          listener->onEvent(event, view, window, universe);
        }
    }
}
