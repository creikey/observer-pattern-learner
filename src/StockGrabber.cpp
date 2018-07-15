#include <nerror1/nerror.h>

#include "StockGrabber.hpp"

StockGrabber::StockGrabber()
{
    PNERROR(low, "Created stock grabber");
}

void StockGrabber::registerObserver(Observer &toRegister)
{
    observers.push_back(std::ref(toRegister));
}

void StockGrabber::unregisterObserver(Observer &toUnregister)
{
    for (auto i = observers.begin(); i != observers.end(); i++)
    {
        if ((*i).get() == toUnregister)
        {
            NERROR(stderr, low, "Successfully unregistered observer");
            observers.erase(i);
            return;
        }
    }
    NERROR(stderr, high, "Attempt to unregister observer that's not registered");
}

void StockGrabber::notifyObserver()
{
    for (auto i = observers.begin(); i != observers.end(); i++)
    {
        (*i).get().update(ibmPrice, aaplPrice, googPrice);
    }
}

void StockGrabber::setIBMPrice(double newIBMPrice)
{
    this->ibmPrice = newIBMPrice;
    notifyObserver();
}
void StockGrabber::setAAPLPrice(double newAAPLPrice)
{
    this->aaplPrice = newAAPLPrice;
    notifyObserver();
}
void StockGrabber::setGOOGPrice(double newGOOGPrice)
{
    this->googPrice = newGOOGPrice;
    notifyObserver();
}

void StockGrabber::incrementPrices(double delta)
{
    this->ibmPrice += delta;
    this->aaplPrice += delta;
    this->googPrice += delta;
    notifyObserver();
}