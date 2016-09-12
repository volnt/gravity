#include <SFML/System.hpp>

#include "SpaceObject.hpp"
#include "Position.hpp"

SpaceObject::SpaceObject(float radius, float mass) : sf::CircleShape(radius)
{
  this->setPosition(sf::Vector2<float>(0, 0));
  this->setOrigin(radius, radius);
  _mass = mass;
  _exists = true;
  _speed = sf::Vector2<float>(0, 0);
}

SpaceObject::SpaceObject(float radius, float mass, sf::Vector2<float> position) : sf::CircleShape(radius)
{
  this->setPosition(position);
  this->setOrigin(radius, radius);
  _mass = mass;
  _exists = true;
  _speed = sf::Vector2<float>(0, 0);
}

float SpaceObject::getMass() const
{
  return (_mass);
}

void SpaceObject::setMass(float mass)
{
  _mass = mass;
}

bool SpaceObject::getExists() const
{
  return (_exists);
}

void SpaceObject::setExists(bool exists)
{
  _exists = exists;
}

sf::Vector2<float> SpaceObject::getSpeed() const
{
  return (_speed);
}

void SpaceObject::setSpeed(sf::Vector2<float> speed)
{
  _speed = speed;
}

void SpaceObject::accelerate(const sf::Vector2<float> &acceleration)
{
  _speed += acceleration;
}

float SpaceObject::getDistance(const SpaceObject &object) const
{
  return (Position::getDistance(this->getPosition(), object.getPosition()) -
          (this->getRadius() + object.getRadius()) * (this->getRadius() + object.getRadius()));
}

float SpaceObject::getDistance(const sf::Vector2<float> &position) const
{
  return (Position::getDistance(this->getPosition(), position) - (this->getRadius() * this->getRadius()));
}

void SpaceObject::collide(SpaceObject &object)
{
  if (&object != this && object.getExists())
    {
      if (this->getDistance(object) <= 0 && this->getMass() >= object.getMass())
        {
          object.setExists(false);
          this->setMass(this->getMass() + object.getMass());
        }
    }
}

void SpaceObject::collide(std::vector<SpaceObject *> &objects)
{
  for (auto &object: objects)
    {
      this->collide(*object);
    }
}

/*
 * Returns acceleration in m/(s*s)
 */
sf::Vector2<float> SpaceObject::getGravitationalForce(const std::vector<SpaceObject *> &objects) const
{
  float force;
  sf::Vector2<float> direction;
  sf::Vector2<float> finalDirection;

  for (auto &object: objects)
    {
      if (object != this && object->getExists())
        {
          direction = Position::getDirection(this->getPosition(), object->getPosition());
          force = UGC * this->getMass() * object->getMass() / Position::getDistance(direction);
          finalDirection += force / this->getMass() * Position::getUnitVector(direction);
        }
    }

  return (finalDirection);
}

void SpaceObject::update(float elapsedTime, std::vector<SpaceObject *> &objects)
{
  if (this->getExists())
    {
      // this->collide(objects);
      this->accelerate(this->getGravitationalForce(objects) * elapsedTime);
      this->move(this->getSpeed());
    }
}
