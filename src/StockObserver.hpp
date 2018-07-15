#ifndef HPP_STOCKOBSERVER
#define HPP_STOCKOBSERVER

#include "Observer.hpp"
#include "Subject.hpp"

class StockObserver : public Observer
{
  private:
    double ibmPrice;
    double aaplPrice;
    double googPrice;
    static int observerIDTracker;
    int observerID;
    std::shared_ptr<Subject> stockGrabber;

  public:
    StockObserver(std::shared_ptr<Subject> myStockGrabber);
    void update(double ibmPrice, double aaplPrice, double googPrice);
    void printPrices();
    bool operator==(Observer &);
    int getID();
    ~StockObserver();
};

#endif // HPP_STOCKOBSERVER