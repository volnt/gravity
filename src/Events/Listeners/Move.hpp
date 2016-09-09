#ifndef __MOVE_HPP__
#define __MOVE_HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "../Listener.hpp"

class Move: public Listener
{
private:
  bool _isMoving;
  sf::Vector2<float> _movingFrom;

public:
  using Listener::Listener;
  virtual void onEvent(const sf::Event &, sf::View &, sf::RenderWindow &);
};

#endif
