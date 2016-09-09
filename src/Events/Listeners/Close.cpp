#include <iostream>
#include "Close.hpp"

void Close::onEvent(const sf::Event &event, sf::View &view, sf::RenderWindow &window)
{
  std::cout << "Received event" << std::endl;
  window.close();
}
