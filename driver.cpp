#include "Rational.h"
#include <iostream>


using namespace std;


void print(const RatNum& r) {
    cout << r.str() << endl;
}

int main() {

    RatNum num1 = RatNum(4);
    RatNum num2 = RatNum();
    RatNum num3 = RatNum(34, -7);
    RatNum num4 = RatNum(-42, 0);


    RatNum sum1 = num1 + num2;
    RatNum sum2 = num3 + num4;

    RatNum dif1 = num1 - num2;
    RatNum dif2 = num3 - num4;

    RatNum prod1 = num1 * num2;
    RatNum prod2 = num3 * num4;

    RatNum quo1 = num1 / num2;
    RatNum quo2 = num3 / num4;

    
    print(num1);
    print(num2);
    print(num3);
    print(num4);
    
    print(sum1);
    print(sum2);

    print(dif1);
    print(dif2);

    print(prod1);
    print(prod2);

    print(quo1);
    print(quo2);



    return 0;
}