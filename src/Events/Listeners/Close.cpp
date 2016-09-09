#include "../../Universe.hpp"
#include "Close.hpp"

void Listener::Close::onEvent(const sf::Event &event, sf::View &view, sf::RenderWindow &window, Universe &universe)
{
  window.close();
}
