#ifndef __MOVEPLANET_HPP__
#define __MOVEPLANET_HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "IListener.hpp"

namespace Listener
{
  class MovePlanet: public IListener
  {
  private:
    SpaceObject *_movingPlanet;

  public:
    using IListener::IListener;
    virtual void onEvent(const sf::Event &, sf::View &, sf::RenderWindow &, Universe &);
  };
}

#endif
