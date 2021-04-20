//Testing file for matrix manager

#include "headers/helper.h"
#include "headers/Rational.h"
#include "headers/Matrix.h"

using namespace std;

template <typename val>
void test(val tested, val expected, int testNum) {
    if (tested == expected)
        return;

    cout << testNum << ": expected result -> " << expected << " | actual result -> " << tested << endl;
}

int main() {

    //test for undefined 
}