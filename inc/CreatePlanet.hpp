#ifndef __CREATEPLANET_HPP__
#define __CREATEPLANET_HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "IListener.hpp"

namespace Listener
{
  class CreatePlanet: public IListener
  {
  private:
    SpaceObject *_movingObject;
    sf::VertexArray *_speedLine;
  public:
    CreatePlanet(const std::vector<sf::Event::EventType> &);
    using IListener::IListener;
    virtual void onEvent(const sf::Event &, sf::View &, sf::RenderWindow &, Universe &);
  };
}

#endif
