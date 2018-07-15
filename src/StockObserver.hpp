#ifndef HPP_STOCKOBSERVER
#define HPP_STOCKOBSERVER

#include "Observer.hpp"
#include "Subject.hpp"

class StockObserver : Observer
{
  private:
    double ibmPrice;
    double aaplPrice;
    double googPrice;
    static const int observerIDTracker = 0;
    int observerID;
    Subject *stockGrabber;

  public:
    StockObserver(Subject *stockGrabber);
    void update(double ibmPrice, double aaplPrice, double googPrice) const;
};

#endif // HPP_STOCKOBSERVER