#ifndef __RatNum__
#define __RatNum__

#include <string>

class RatNum {

private:

    int den;
    int num;
    bool undefined;

    void simplify();
    int gcf(int, int) const;
    int lcm(int, int) const;
    int max(int, int) const;
    int min(int, int) const;
    int abs(int) const;

public:

    RatNum();
    RatNum(int);
    RatNum(int, int);

    RatNum operator+(int) const;
    RatNum operator-(int) const;
    RatNum operator*(int) const;
    RatNum operator/(int) const;

    RatNum operator+(const RatNum&) const;
    RatNum operator-(const RatNum&) const;
    RatNum operator*(const RatNum&) const;
    RatNum operator/(const RatNum&) const;

    std::string str() const;


};



#endif