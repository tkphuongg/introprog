// #include "hailstonefunc.h"


int hailstonefun(int n) {
    int hail = 0;
    while(n != 1)
    {
        if(n % 2 == 0)
        {
            n /= 2;
            hail++;
        }
        else
        {
            n = 3 * n + 1;
            hail++;
        }
    }
    return hail;
}