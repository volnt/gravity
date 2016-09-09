#ifndef __CLOSE_HPP__
#define __CLOSE_HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "../IListener.hpp"

namespace Listener
{
  class Close: public IListener
  {
  public:
    using IListener::IListener;
    virtual void onEvent(const sf::Event &, sf::View &, sf::RenderWindow &, Universe &);
  };
}

#endif
