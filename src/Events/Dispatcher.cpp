#include "Dispatcher.hpp"

void Dispatcher::registerListener(Listener &listener)
{
  for (auto const &eventType: listener.getEventTypes())
    {
      if (_listeners.find(eventType) == _listeners.end())
        {
          _listeners[eventType] = std::vector<Listener *>();
        }
      _listeners[eventType].push_back(&listener);
    }
}

void Dispatcher::dispatch(const sf::Event &event) const
{
  if (_listeners.find(event.type) != _listeners.end())
    {
      for (const auto &listener: _listeners.find(event.type)->second)
        {
          listener->onEvent(event);
        }
    }
}
