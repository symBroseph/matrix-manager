#ifndef _HELPER_
#define _HELPER_

int gcf(int a, int b) {
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

int lcm(int a, int b) {
    return (a * b) / gcf(a, b);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}
int min(int a, int b) {
    return (a < b) ? a : b;
}
int abs(int n) {
    return (n < 0) ? 0 - n : n;
}


#endif