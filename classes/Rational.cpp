#include "Rational.h"

using namespace std;


RatNum::RatNum(int n, int d) {
    num = n;
    den = d;
    undefined = false;
    simplify();
}
RatNum::RatNum(int n) {
    num = n;
    den = 1;
    undefined = false;
    simplify();
}
RatNum::RatNum() {
    num = 1;
    den = 1;
    undefined = false;
}





RatNum operator+(const RatNum& l, const RatNum& r) {
    RatNum result;
    //check if defined
    if (l.undefined || r.undefined) {
        result = RatNum(0, 0);
        result.undefined = true;
        return result;
    }

    int d = help::lcm(l.den, r.den);
    int n = ((d/l.den) * l.num) + ((d/r.den) * r.num);

    result = RatNum(n, d);
    result.simplify();

    return result;
}
RatNum operator-(const RatNum& l, const RatNum& r) {
    RatNum result;
    //check if defined
    if (l.undefined || r.undefined) {
        result = RatNum(0, 0);
        result.undefined = true;
        return result;
    }

    int d = help::lcm(l.den, r.den);
    int n = ((d/l.den) * l.num) - ((d/r.den) * r.num);

    result = RatNum(n, d);
    result.simplify();
    
    return result;
}

RatNum operator*(const RatNum& l, const RatNum& r) {
    RatNum result;
    //check if defined
    if (l.undefined || r.undefined) {
        result = RatNum(0, 0);
        result.undefined = true;
        return result;
    }
    
    result = RatNum(l.num * r.num, l.den * r.den);
    result.simplify();

    return result;
}
RatNum operator/(const RatNum& l, const RatNum& r) {
    RatNum result;
    //check if defined
    if (l.undefined || r.undefined) {
        result = RatNum(0, 0);
        result.undefined = true;
        return result;
    }

    result = RatNum(l.num * r.den, l.den * r.num);
    result.simplify();

    return result;
}



// std::istream& operator>>(std::istream& ins, RatNum& num) {
//     ins >> num;
//     return ins;
// }
std::ostream& operator<<(std::ostream& outs, const RatNum& num) {
    outs << num.str();
    return outs;
}


std::string RatNum::str() const {
    if (undefined) {
        return "undefined";
    }

    std::string expression;
    expression = std::to_string(num);
    if (den != 1)
    expression += '/' + std::to_string(den);

    return expression;

}



void RatNum::simplify() {

    //check if defined
    if (den == 0) {
        num = 0;
        undefined = true;
        return;
    }

    //reduce
    int f = help::gcf(num, den);
    num /= f;
    den /= f;

    //make sure numerator has correct sign
    int sign = num / den;
    num = abs(num);
    den = abs(den);

    if (sign < 0) 
        num = 0 - num;

}
