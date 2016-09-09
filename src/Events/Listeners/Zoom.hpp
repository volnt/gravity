#ifndef __ZOOM_HPP__
#define __ZOOM_HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "../Listener.hpp"

class Zoom: public Listener
{
public:
  using Listener::Listener;
  virtual void onEvent(const sf::Event &, sf::View &, sf::RenderWindow &);
};

#endif
