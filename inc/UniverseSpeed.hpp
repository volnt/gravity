#ifndef __UNIVERSESPEED_HPP__
#define __UNIVERSESPEED_HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "IListener.hpp"

namespace Listener
{
  class UniverseSpeed: public IListener
  {
  public:
    using IListener::IListener;
    virtual void onEvent(const sf::Event &, sf::View &, sf::RenderWindow &, Universe &);
  };
}

#endif
