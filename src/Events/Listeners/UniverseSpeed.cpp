#include "Universe.hpp"
#include "UniverseSpeed.hpp"

void Listener::UniverseSpeed::onEvent(const sf::Event &event, sf::View &view, sf::RenderWindow &window, Universe &universe)
{
  if (event.key.code == sf::Keyboard::Key::Up)
    {
      universe.increaseSpeed();
    }
  else if (event.key.code == sf::Keyboard::Key::Down)
    {
      universe.decreaseSpeed();
    }
}
