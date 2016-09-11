#ifndef __HUDOBJECT_HPP__
#define __HUDOBJECT_HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class HUDObject: public sf::Drawable
{
public:
  virtual void update(float) = 0;
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;
};

#endif
