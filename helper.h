// #pragma once

#ifndef __HELPER__
#define __HELPER__


namespace help {

    static int max(int a, int b) {
        return (a > b) ? a : b;
    }
    static int min(int a, int b) {
        return (a < b) ? a : b;
    }
    static int abs(int n) {
        return (n < 0) ? 0 - n : n;
    }

    static int gcf(int a, int b) {
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

    static int lcm(int a, int b) {
        return (a * b) / gcf(a, b);
    }

}


#endif