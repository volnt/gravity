#include "Zoom.hpp"

void Listener::Zoom::onEvent(const sf::Event &event, sf::View &view, sf::RenderWindow &window)
{
  view.zoom(1 - event.mouseWheelScroll.delta / 10.f);
}
