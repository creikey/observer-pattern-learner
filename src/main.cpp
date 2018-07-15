#include <iostream>
#include <memory>
#include <thread>
#ifdef __linux__
#include <unistd.h>
#elif defined(__MINGW32__)
#include <dos.h>
#endif
#include <nerror1/nerror.h>

#include "Observer.hpp"
#include "Subject.hpp"
#include "StockGrabber.hpp"
#include "StockObserver.hpp"

void increment_stock_prices(std::shared_ptr<StockGrabber> stockGrabber, float amount, float time_interval, int times)
{
    for (int i = 0; i < times; i++)
    {
        stockGrabber->incrementPrices(amount);
        sleep(time_interval);
    }
}

int main(int argc, char **argv)
{
    auto myStocks = std::make_shared<StockGrabber>();
    myStocks->setIBMPrice(197.00);
    myStocks->setAAPLPrice(677.60);
    myStocks->setGOOGPrice(676.40);

    std::unique_ptr<StockObserver> observer1 = std::make_unique<StockObserver>(std::static_pointer_cast<Subject>(myStocks));
    std::unique_ptr<StockObserver> observer2 = std::make_unique<StockObserver>(std::static_pointer_cast<Subject>(myStocks));

    std::vector<std::shared_ptr<std::thread>> threads;
    for (int i = 0; i < 4; i++)
    {
        threads.push_back(std::make_shared<std::thread>(increment_stock_prices, std::shared_ptr<StockGrabber>(myStocks), 1.00, i, 3));
    }
    for (auto curThread = threads.begin(); curThread != threads.end(); curThread++)
    {
        (*curThread)->join();
    }
    return 0;
}