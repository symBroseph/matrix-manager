#include "Rational.h"
#include "helper.h"
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

    
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;
    cout << num4 << endl;
    
    cout << sum1 << endl;
    cout << sum2 << endl;

    cout << dif1 << endl;
    cout << dif2 << endl;

    cout << prod1 << endl;
    cout << prod2 << endl;

    cout << quo1 << endl;
    cout << quo2 << endl;



    return 0;
}