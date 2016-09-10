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
  SpaceObject(float, float);
  SpaceObject(float, float, sf::Vector2<float>);

  /* Getters */
  sf::Vector2<float> getSpeed() const;
  float getMass() const;
  bool getExists() const;

  /* Setters */
  void setSpeed(const sf::Vector2<float>);
  void setMass(const float);
  void setExists(const bool);

  /* Methods */
  void accelerate(const sf::Vector2<float> &);
  float getDistance(const SpaceObject &) const;
  void collide(SpaceObject &);
  void collide(std::vector<SpaceObject *> &);
  sf::Vector2<float> getGravitationalForce(const std::vector<SpaceObject *> &) const;

  void update(float, std::vector<SpaceObject *> &);
};

#endif
