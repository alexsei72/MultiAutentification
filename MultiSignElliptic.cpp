#include "MultiSignElliptic.h"
#include"ap/ap.hpp"
#include"Elliptic.hpp"

Elliptic MultiSignElliptic(ap_int<512> q, ap_int<512> k)
{
	Elliptic elliptic;
	elliptic = k * elliptic;
	return elliptic;
}