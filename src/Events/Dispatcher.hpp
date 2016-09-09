#ifndef __DISPATCHER_HPP__
#define __DISPATCHER_HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "IListener.hpp"

class Dispatcher
{
private:
  std::map<sf::Event::EventType, std::vector<IListener *>> _listeners;

public:
  void registerListener(IListener &);
  void dispatch(const sf::Event &, sf::View &, sf::RenderWindow &);
};

#endif
