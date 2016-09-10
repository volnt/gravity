#include "HUD.hpp"

void HUD::addObject(HUDObject *object)
{
  _objects.push_back(object);
}

void HUD::update(float elapsedTime)
{
  for (auto &object: _objects)
    {
      object->update(elapsedTime);
    }
}

void HUD::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  for (auto &object: _objects)
    {
      target.draw(*object, states);
    }
}
