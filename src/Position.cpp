#include <cmath>
#include <SFML/System.hpp>

#include "Position.hpp"

sf::Vector2<float> Position::getDirection(const sf::Vector2<float> &first, const sf::Vector2<float> &second)
{
  return (second - first);
}

sf::Vector2<float> Position::getUnitVector(const sf::Vector2<float> &vector)
{
  return (vector / (float)sqrt(Position::getDistance(vector)));
}

float Position::getDistance(const sf::Vector2<float> &first, const sf::Vector2<float> &second)
{
  auto direction = getDirection(first, second);

  return (direction.x * direction.x + direction.y * direction.y);
}

float Position::getDistance(const sf::Vector2<float> &vector)
{
  return (vector.x * vector.x + vector.y * vector.y);
}
