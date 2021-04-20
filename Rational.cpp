#include "Rational.h"


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




RatNum RatNum::operator+(int n) const {
    return *this + RatNum(n);
}
RatNum RatNum::operator-(int n) const {
    return *this - RatNum(n);
}
RatNum RatNum::operator*(int n) const {
    return *this * RatNum(n);
}
RatNum RatNum::operator/(int n) const {
    return *this / RatNum(n);
}



RatNum RatNum::operator+(const RatNum& r) const {
    RatNum result;
    //check if defined
    if (undefined || r.undefined) {
        result = RatNum(0, 0);
        result.undefined = true;
        return result;
    }

    int d = lcm(den, r.den);
    int n = ((d/den) * num) + ((d/r.den) * r.num);

    result = RatNum(n, d);
    result.simplify();

    return result;
}
RatNum RatNum::operator-(const RatNum& r) const {
    RatNum result;
    //check if defined
    if (undefined || r.undefined) {
        result = RatNum(0, 0);
        result.undefined = true;
        return result;
    }

    int d = lcm(den, r.den);
    int n = ((d/den) * num) - ((d/r.den) * r.num);

    result = RatNum(n, d);
    result.simplify();
    
    return result;
}
RatNum RatNum::operator*(const RatNum& r) const {
    RatNum result;
    //check if defined
    if (undefined || r.undefined) {
        result = RatNum(0, 0);
        result.undefined = true;
        return result;
    }
    
    result = RatNum(num * r.num, den * r.den);
    result.simplify();

    return result;
}
RatNum RatNum::operator/(const RatNum& r) const {
    RatNum result;
    //check if defined
    if (undefined || r.undefined) {
        result = RatNum(0, 0);
        result.undefined = true;
        return result;
    }

    result = RatNum(num * r.den, den * r.num);
    result.simplify();

    return result;
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
    int f = gcf(num, den);
    num /= f;
    den /= f;

    //make sure numerator has correct sign
    int sign = num / den;
    num = abs(num);
    den = abs(den);

    if (sign < 0) 
        num = 0 - num;

}

int RatNum:: gcf(int a, int b) const {
    int u = max(abs(a), abs(b));
    int v = min(abs(a), abs(b));
    int r = u % v;

    while (r != 0) {
        u = v;
        v = r;
        r = u % v;
    }

    return v;
}

int RatNum::lcm(int a, int b) const {
    return (a * b) / gcf(a, b);
}

int RatNum::max(int a, int b) const {
    return (a > b) ? a : b;
}
int RatNum::min(int a, int b) const {
    return (a < b) ? a : b;
}
int RatNum::abs(int n) const {
    return (n < 0) ? 0 - n : n;
}