#ifndef __SPACEOBJECT_HPP__
#define __SPACEOBJECT_HPP__

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class SpaceObject: public sf::CircleShape
{
private:
  float _mass;

public:
  SpaceObject(float radius);

  float getMass();
};

#endif
