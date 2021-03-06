#ifndef __ZOOM_HPP__
#define __ZOOM_HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "IListener.hpp"
#include "Universe.hpp"


namespace Listener
{
  class Zoom: public IListener
  {
  public:
    using IListener::IListener;
    virtual void onEvent(const sf::Event &, sf::View &, sf::RenderWindow &, Universe &);
  };
}

#endif
