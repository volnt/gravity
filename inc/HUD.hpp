#ifndef __HUD_HPP__
#define __HUD_HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "HUDObject.hpp"
#include "Universe.hpp"

class HUD: public sf::Drawable
{
private:
  std::vector<HUDObject *> _objects;

public:
  void addObject(HUDObject *);

  void update(float, const sf::RenderWindow &, const sf::View &, const Universe &);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif
