#include "Universe.hpp"

void Universe::addObject(SpaceObject &object)
{
  _objects.push_back(&object);
}

SpaceObject *Universe::getObjectAt(const sf::Vector2<float> &position) const
{
  for (auto &object: _objects)
    {
      if (object->getDistance(position) <= 0)
        {
          return (object);
        }
    }
  return (NULL);
}

void Universe::update(float elapsedTime)
{
  for (auto &object: _objects)
    {
      object->update(elapsedTime, _objects);
    }
}

void Universe::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  for (auto &object: _objects)
    {
      if (object->getExists())
        {
          target.draw(*object, states);
        }
    }
}
