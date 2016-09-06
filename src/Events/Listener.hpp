#ifndef __LISTENER_HPP__
#define __LISTENER_HPP__

#include <SFML/System.hpp>

class Listener
{
public:
  virtual void onEvent(const Event &) = 0;
};

#endif
