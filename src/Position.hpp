#ifndef __POSITION_HPP__
#define __POSITION_HPP__

#include <SFML/System.hpp>

sf::Vector2<float> getDirection(const sf::Vector2<float> &, const sf::Vector2<float> &);
float getDistance(const sf::Vector2<float> &, const sf::Vector2<float> &);
float getDistance(const sf::Vector2<float> &);

#endif
