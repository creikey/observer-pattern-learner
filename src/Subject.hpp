#ifndef HPP_SUBJECT
#define HPP_SUBJECT

#include <memory>
#include "Observer.hpp"

class Subject
{
public:
  virtual void registerObserver(Observer &) = 0;
  virtual void unregisterObserver(Observer &) = 0;
  virtual void notifyObserver() = 0;
};

#endif // HPP_SUBJECT