#ifndef __MOVE_HPP__
#define __MOVE_HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "../IListener.hpp"

namespace Listener
{
  class Move: public IListener
  {
  private:
    bool _isMoving;
    sf::Vector2<float> _movingFrom;

  public:
    Move(const std::vector<sf::Event::EventType> &);
    virtual void onEvent(const sf::Event &, sf::View &, sf::RenderWindow &);
  };
}

#endif
