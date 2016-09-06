#ifndef __DISPATCHER_HPP__
#define __DISPATCHER_HPP__

#include <SFML/System.hpp>

#include "Listener.hpp"

class Dispatcher
{
private:
  std::vector<Listener> _listerners;

public:
  void registerListener(const Listener &);
  void unregisterListener(const Listener &);
  void dispatch(const Event &);
};

#endif
