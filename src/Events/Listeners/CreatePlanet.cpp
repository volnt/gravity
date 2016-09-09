#include <SFML/Graphics.hpp>

#include "../../Universe.hpp"
#include "../../Planet.hpp"
#include "CreatePlanet.hpp"

void Listener::CreatePlanet::onEvent(const sf::Event &event, sf::View &view, sf::RenderWindow &window, Universe &universe)
{
  if (event.type == sf::Event::MouseButtonPressed)
    {
      if (event.mouseButton.button == sf::Mouse::Left)
        {
          auto mousePosition = sf::Vector2<int>(event.mouseButton.x, event.mouseButton.y);
          auto planetPosition = sf::Vector2<float>(window.mapPixelToCoords(mousePosition, view));
          auto *planet = new Planet(10.f, 1, planetPosition);

          planet->setFillColor(sf::Color::Blue);
          universe.addObject(*planet);
        }
    }
}
