#ifndef __LISTENER_HPP__
#define __LISTENER_HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Listener
{
private:
  std::vector<sf::Event::EventType> _eventTypes;

public:
  const std::vector<sf::Event::EventType> &getEventTypes() const;

  virtual void onEvent(const sf::Event &) const = 0;
};

#endif
