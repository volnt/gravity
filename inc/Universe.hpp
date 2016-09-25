#ifndef __UNIVERSE_HPP__
#define __UNIVERSE_HPP__

#include <SFML/System.hpp>

#include "SpaceObject.hpp"

class Universe: public sf::Drawable
{
private:
  std::vector<SpaceObject *> _objects;
  SpaceObject *_objectAtCursor;
  float _speed;

public:
  Universe();
  Universe(float);

  float getSpeed() const;
  void increaseSpeed();
  void decreaseSpeed();
  void addObject(SpaceObject &);

  SpaceObject *getObjectAtCursor() const;
  SpaceObject *getObjectAt(const sf::Vector2<float> &) const;

  void update(float, const sf::RenderWindow &, const sf::View &);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif
