#ifndef __RatNum__
#define __RatNum__

#include <string>
#include <iostream>
#include "helper.h"

class RatNum {

private:

    int den;
    int num;
    bool undefined;

    void simplify();

public:

    RatNum();
    RatNum(int);
    RatNum(int, int);


    friend RatNum operator+(const RatNum&, const RatNum&);
    friend RatNum operator-(const RatNum&, const RatNum&);
    friend RatNum operator*(const RatNum&, const RatNum&);
    friend RatNum operator/(const RatNum&, const RatNum&);

    // friend std::istream& operator>>(std::istream&, RatNum&);
    friend std::ostream& operator<<(std::ostream&, const RatNum&);

    std::string str() const;


};



#endif