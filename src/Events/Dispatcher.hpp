#ifndef __DISPATCHER_HPP__
#define __DISPATCHER_HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Listener.hpp"

class Dispatcher
{
private:
  std::map<sf::Event::EventType, std::vector<Listener *>> _listeners;

public:
  void registerListener(Listener &);
  void dispatch(const sf::Event &) const;
};

#endif
