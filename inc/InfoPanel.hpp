#ifndef __INFOPANEL_HPP__
#define __INFOPANEL_HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "HUDObject.hpp"
#include "Universe.hpp"

class InfoPanel: public HUDObject
{
private:
  sf::Font _font;
  sf::Text _text;

public:
  InfoPanel();
  void update(float, const sf::RenderWindow &, const sf::View &, const Universe &);
  virtual void draw(sf::RenderTarget &, sf::RenderStates) const;
};

#endif
