#include "HUD.hpp"

void HUD::addObject(HUDObject *object)
{
  _objects.push_back(object);
}

void HUD::update(float elapsedTime, const sf::RenderWindow &window, const sf::View &view, const Universe &universe)
{
  for (auto &object: _objects)
    {
      object->update(elapsedTime, window, view, universe);
    }
}

void HUD::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  for (auto &object: _objects)
    {
      target.draw(*object, states);
    }
}
