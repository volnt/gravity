#ifndef __POSITION_HPP__
#define __POSITION_HPP__

#include <SFML/System.hpp>

namespace Position
{
  sf::Vector2<float> getDirection(const sf::Vector2<float> &, const sf::Vector2<float> &);
  sf::Vector2<float> getUnitVector(const sf::Vector2<float> &);

  float getDistance(const sf::Vector2<float> &, const sf::Vector2<float> &);
  float getDistance(const sf::Vector2<float> &);
}

#endif
