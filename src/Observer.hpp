#ifndef HPP_OBSERVER
#define HPP_OBSERVER

class Observer
{
  public:
    virtual void update(double ibmPrice, double aaplPrice, double googPrice) const = 0;
    virtual bool operator==(Observer &) = 0;
};

#endif // HPP_OBSERVER