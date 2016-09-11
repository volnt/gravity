#ifndef __LISTENER_HPP__
#define __LISTENER_HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Universe.hpp"

class IListener
{
private:
  std::vector<sf::Event::EventType> _eventTypes;

public:
  IListener(const std::vector<sf::Event::EventType> &);
  ~IListener();
  const std::vector<sf::Event::EventType> &getEventTypes() const;

  template <typename T, typename U>
  const sf::Vector2<T> pixelToCoord(const sf::Vector2<U> &, const sf::RenderWindow &, const sf::View &) const;

  virtual void onEvent(const sf::Event &, sf::View &, sf::RenderWindow &, Universe &) = 0;
};

#endif
