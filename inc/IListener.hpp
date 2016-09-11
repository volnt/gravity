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

  virtual void onEvent(const sf::Event &, sf::View &, sf::RenderWindow &, Universe &) = 0;

  /* Listeners helpers */
  const sf::Vector2<float> pixelToCoord(const sf::Vector2<int> &, const sf::RenderWindow &, const sf::View &) const;
  const sf::Vector2<float> pixelToCoord(const sf::Vector2<float> &, const sf::RenderWindow &, const sf::View &) const;
};

#endif
