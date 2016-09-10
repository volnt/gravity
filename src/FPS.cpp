#include "FPS.hpp"

FPS::FPS()
{
  _font.loadFromFile("VCR_OSD_Mono.ttf");
  _text.setFont(_font);
  _text.setPosition(20, 20);
  _text.setColor(sf::Color::White);
  _text.setCharacterSize(10);
}

void FPS::update(float elpasedTime)
{
  _text.setString(std::to_string((int)(1.f / elpasedTime)) + " fps");
}

void FPS::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(_text, states);
}
