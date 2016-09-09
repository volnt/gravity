#include "Universe.hpp"

void Universe::addObject(SpaceObject &object)
{
  _objects.push_back(object);
}

void Universe::update()
{
  for (auto &object: _objects)
    {
      if (object.getExists())
        {
          object.collide(_objects);
          object.setSpeed(object.getSpeed() + object.getGravitationalForce(_objects));
          object.move(object.getSpeed() * 10.f);
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
