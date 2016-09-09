#include <iostream>
#include "Zoom.hpp"

void Zoom::onEvent(const sf::Event &event, sf::View &view, sf::RenderWindow &window)
{
  std::cout << "Received event" << std::endl;
  view.zoom(1 - event.mouseWheelScroll.delta / 10.f);
}
