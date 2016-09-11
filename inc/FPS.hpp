#ifndef __FPS_HPP__
#define __FPS_HPP__

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "HUDObject.hpp"

class FPS: public HUDObject
{
private:
  sf::Font _font;
  sf::Text _text;

public:
  FPS();
  void update(float);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif
