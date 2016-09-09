#include "Close.hpp"

void Listener::Close::onEvent(const sf::Event &event, sf::View &view, sf::RenderWindow &window)
{
  window.close();
}
