#include "SpaceObject.hpp"
#include "InfoPanel.hpp"

InfoPanel::InfoPanel()
{
  _font.loadFromFile("VCR_OSD_Mono.ttf");
  _text.setFont(_font);
  _text.setPosition(20, 60);
  _text.setColor(sf::Color::White);
  _text.setCharacterSize(10);
}

void InfoPanel::update(float elpasedTime, const sf::RenderWindow &window, const sf::View &view, const Universe &universe)
{
  SpaceObject *object = universe.getObjectAtCursor();

  if (object)
    {
      _text.setString("Position : " + std::to_string((int)object->getPosition().x) + ", " + std::to_string((int)object->getPosition().y) + "\n" +
                      "Speed : " + std::to_string(object->getSpeed().x) + ", " + std::to_string(object->getSpeed().y) + "\n" +
                      "Mass : " + std::to_string((int)object->getMass()));

    }
  else
    {
      _text.setString("");
    }
}

void InfoPanel::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(_text, states);
}
