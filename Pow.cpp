#include"ap/ap.hpp"
#include <iostream>
using namespace std;
ap_int<512> modexp(ap_int<512> x, ap_int<512> y, ap_int<512> N)
{
    if (y == 0) return 1;
    ap_int<512> z = modexp(x, y / 2, N);
    if (y % 2 == 0)
        return (z * z) % N;
    else
        return (x * z * z) % N;
}
