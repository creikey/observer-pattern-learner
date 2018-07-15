#include <nerror1/nerror.h>

#include "StockObserver.hpp"

int StockObserver::observerIDTracker = 0;

StockObserver::~StockObserver()
{
    stockGrabber->unregisterObserver(*this);
}

StockObserver::StockObserver(std::shared_ptr<Subject> myStockGrabber) : stockGrabber(myStockGrabber)
{
    PNERROR(low, "Created new stock observer");
    StockObserver::observerIDTracker++;
    observerID = StockObserver::observerIDTracker;
    std::string observerMessage = "New Observer with ID " + std::to_string(observerID);
    PNERROR(low, observerMessage.c_str());
    stockGrabber->registerObserver(*this);
}

void StockObserver::update(double inIBMPrice, double inAAPLPrice, double inGOOGPrice)
{
    ibmPrice = inIBMPrice;
    aaplPrice = inAAPLPrice;
    googPrice = inGOOGPrice;
    printPrices();
}

void StockObserver::printPrices()
{
    std::string pricesMessage;
    pricesMessage += "-- Prices of StockObserver with ID " + std::to_string(observerID) + " --\n";
    pricesMessage += "ibm  - " + std::to_string(ibmPrice);
    pricesMessage += "aapl - " + std::to_string(aaplPrice);
    pricesMessage += "goog - " + std::to_string(googPrice);
    PNERROR(low, pricesMessage.c_str());
}

bool StockObserver::operator==(Observer &inStockObserver)
{
    if (observerID == inStockObserver.getID())
    {
        return true;
    }
    return false;
}

int StockObserver::getID()
{
    return observerID;
}