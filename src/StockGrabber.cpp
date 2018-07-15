#include <nerror1/nerror.h>

#include "StockGrabber.hpp"

StockGrabber::StockGrabber()
{
}

void StockGrabber::registerObserver(const Observer *toRegister)
{
    observers.push_back(toRegister);
}

void StockGrabber::unregisterObserver(const Observer *toUnregister)
{
    for (auto i = observers.begin(); i != observers.end(); i++)
    {
        if (*i == toUnregister)
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
        (*i)->update(ibmPrice, aaplPrice, googPrice);
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