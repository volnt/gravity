#include "FPS.hpp"

FPS::FPS()
{
  _font.loadFromFile("resources/VCR_OSD_Mono.ttf");
  _text.setFont(_font);
  _text.setPosition(20, 20);
  _text.setColor(sf::Color::White);
  _text.setCharacterSize(10);
}

void FPS::update(float elpasedTime, const sf::RenderWindow &window, const sf::View &view, const Universe &universe)
{
  _text.setString(std::to_string((int)(1.f / elpasedTime)) + " fps\n" +
                  "Universe speed : x" + std::to_string(universe.getSpeed()));
}

void FPS::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(_text, states);
}
