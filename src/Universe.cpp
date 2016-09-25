#include <iostream>
#include "Universe.hpp"

Universe::Universe()
{
  std::cout << "Hello Universe !" << std::endl;
  _speed = 1.f;
}

Universe::Universe(float speed)
{
  _speed = speed;
}

float Universe::getSpeed() const
{
  return (_speed);
}

void Universe::increaseSpeed()
{
  _speed *= 2.f;
}

void Universe::decreaseSpeed()
{
  _speed /= 2.f;
}

void Universe::addObject(SpaceObject &object)
{
  _objects.push_back(&object);
}

SpaceObject *Universe::getObjectAtCursor() const
{
  return (_objectAtCursor);
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

void Universe::update(float elapsedTime, const sf::RenderWindow &window, const sf::View &view)
{
  auto mousePosition = sf::Mouse::getPosition(window);
  auto objectPosition = sf::Vector2<float>(window.mapPixelToCoords(mousePosition, view));

  _objectAtCursor = getObjectAt(objectPosition);

  for (auto &object: _objects)
    {
      object->update(elapsedTime * _speed, _objects);
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
