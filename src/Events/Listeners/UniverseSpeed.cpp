#include "Universe.hpp"
#include "UniverseSpeed.hpp"

void Listener::UniverseSpeed::onEvent(const sf::Event &event, sf::View &view, sf::RenderWindow &window, Universe &universe)
{
  if (event.key.code == sf::Keyboard::Key::Add)
    {
      universe.increaseSpeed();
    }
  else if (event.key.code == sf::Keyboard::Key::Subtract)
    {
      universe.decreaseSpeed();
    }
}
