#include <SFML/System.hpp>

#include "SpaceObject.hpp"

SpaceObject::SpaceObject(float radius)
{
  this->setRadius(radius);
}

float SpaceObject::getMass()
{
  return (_mass);
}
