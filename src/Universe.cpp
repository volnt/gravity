#include "Universe.hpp"

void Universe::addObject(SpaceObject &object)
{
  _objects.push_back(object);
}

void Universe::update(float elpasedTime)
{
  for (auto &object: _objects)
    {
      if (object.getExists())
        {
          object.collide(_objects);
          object.accelerate(object.getGravitationalForce(_objects) * elpasedTime);
          object.move(object.getSpeed());
        }
    }
}

void Universe::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  for (auto &object: _objects)
    {
      if (object.getExists())
        {
          target.draw(object, states);
        }
    }
}
