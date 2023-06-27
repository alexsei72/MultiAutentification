#include "MultiSign.h"
#include <iostream>
#include"ap/ap.hpp"
#include"Pow.h"

ap_int<512> MultiSign(ap_int<512> a, ap_int<512> p, ap_int<512> q, ap_int<512> g, ap_int<512> k)
{
	ap_int<512> r = modexp(g, k, q);
}