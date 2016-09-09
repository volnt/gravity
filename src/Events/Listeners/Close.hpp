#ifndef __CLOSE_HPP__
#define __CLOSE_HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "../Listener.hpp"

class Close: public Listener
{
public:
  using Listener::Listener;
  virtual void onEvent(const sf::Event &, sf::View &, sf::RenderWindow &);
};

#endif
