#ifndef __HUDOBJECT_HPP__
#define __HUDOBJECT_HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "Universe.hpp"

class HUDObject: public sf::Drawable
{
public:
  virtual void update(float, const sf::RenderWindow &, const sf::View &, const Universe &) = 0;
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;
};

#endif
