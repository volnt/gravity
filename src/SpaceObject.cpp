#include <SFML/System.hpp>

#include "SpaceObject.hpp"

SpaceObject::SpaceObject(float radius, float mass)
{
  this->setRadius(radius);
  this->setOrigin(radius, radius);
  _mass = mass;
}

SpaceObject::SpaceObject(float radius, float mass, sf::Vector2<float> position)
{
  this->setRadius(radius);
  this->setOrigin(radius, radius);
  this->setPosition(position);
  _mass = mass;
}

float SpaceObject::getMass()
{
  return (_mass);
}

void SpaceObject::setMass(const float mass)
{
  _mass = mass;
}

bool SpaceObject::getExists()
{
  return (_exists);
}

void SpaceObject::setExists(const bool exists)
{
  _exists = exists;
}


void SpaceObject::collide(std::vector<SpaceObject> &objects)
{
  sf::Vector2<float> direction;

  for (size_t i = 0; i < objects.size(); i++)
    {
      if (&objects[i] != this && objects[i].getExists())
        {
          direction = this->getDirection(objects[i]);
          if (direction.x * direction.x + direction.y * direction.y <=
              (this->getRadius() + objects[i].getRadius()) * (this->getRadius() + objects[i].getRadius()) &&
              this->getMass() >= objects[i].getMass())
            {
              objects[i].setExists(false);
              this->setMass(this->getMass() + objects[i].getMass());
            }
        }
    }
}

sf::Vector2<float> SpaceObject::getGravitationalForce(std::vector<SpaceObject> &objects)
{
  float force;
  sf::Vector2<float> direction;
  sf::Vector2<float> finalDirection;

  for (size_t i = 0; i < objects.size(); i++)
    {
      if (&objects[i] != this && objects[i].getExists())
        {
          direction = this->getDirection(objects[i]);
          force = (UGC * this->getMass() * objects[i].getMass() /
                   (direction.x * direction.x + direction.y * direction.y));
          finalDirection += (force / this->getMass() * direction);
        }
    }
  return (finalDirection);
}

sf::Vector2<float> SpaceObject::getDirection(const SpaceObject object)
{
  return (object.getPosition() - this->getPosition());
}
