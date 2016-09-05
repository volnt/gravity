#ifndef __SPACEOBJECT_HPP__
#define __SPACEOBJECT_HPP__

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#define UGC 0.00000000006674

class SpaceObject: public sf::CircleShape
{
private:
  float _mass;
  bool _exists;
  sf::Vector2<float> _speed;

public:
  SpaceObject(const float, const float);
  SpaceObject(const float, const float, const sf::Vector2<float>);

  sf::Vector2<float> getSpeed();
  void setSpeed(const sf::Vector2<float>);
  float getMass();
  void setMass(const float);
  bool getExists();
  void setExists(const bool);

  void collide(std::vector<SpaceObject> &);
  sf::Vector2<float> getGravitationalForce(std::vector<SpaceObject> &);
  sf::Vector2<float> getDirection(const SpaceObject);
};

#endif
