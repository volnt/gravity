#ifndef __UNIVERSE_HPP__
#define __UNIVERSE_HPP__

#include <SFML/System.hpp>

#include "SpaceObject.hpp"

class Universe: public sf::Drawable
{
private:
  std::vector<SpaceObject> _objects;

public:
  void addObject(SpaceObject &);

  void update();
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif
