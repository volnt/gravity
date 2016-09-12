#ifndef __MOVEOBJECT_HPP__
#define __MOVEOBJECT_HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "IListener.hpp"

namespace Listener
{
  class MoveObject: public IListener
  {
  private:
    SpaceObject *_movingObject;

  public:
    MoveObject(const std::vector<sf::Event::EventType> &);
    using IListener::IListener;
    virtual void onEvent(const sf::Event &, sf::View &, sf::RenderWindow &, Universe &);
  };
}

#endif
