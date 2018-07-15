#ifndef HPP_STOCKGRABBER
#define HPP_STOCKGRABBER

#include <vector>
#include "Subject.hpp"

class StockGrabber : Subject
{
  private:
    std::vector<const Observer *> observers;
    double ibmPrice;
    double aaplPrice;
    double googPrice;

  public:
    StockGrabber();
    void registerObserver(const Observer *);
    void unregisterObserver(const Observer *);
    void notifyObserver();
    void setIBMPrice(double newIBMPrice);
    void setAAPLPrice(double newAAPLPrice);
    void setGOOGPrice(double newGOOGPrice);
};

#endif // HPP_STOCKGRABBER