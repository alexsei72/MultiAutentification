#include "MultiAuthElliptic.h"
#include"Elliptic.hpp"
#include <iostream>
#include"ap/ap.hpp"
#include"Pow.h"
#include"GetH.h"
using namespace std;
#include "DEN22/src/frn.h"
#include "Token_create.h"
#include "Token_create.cpp"
#include "MultiSignElliptic.h"
#include"Elliptic.hpp"



class MultiAuthElliptic
{
public:
	string token;
	ap_int<512> key;
	ap_int<512> s[3];


	MultiAuthElliptic MAuthE(ap_int<512> h[3], ap_int<512> a[3], ap_int<512> q,  PRG Connect)
	{
		MultiAuthElliptic Auth;
		ap_int<512> k[3] = GetRandomElement(Connect);
		Elliptic Ci[4];
		for (int i = 0; i < 3; i++)
		{
			Ci[i] = MultiSignElliptic(q,  k[i]);
		}
		Ci[3] = Publication(Ci[0], Ci[1], Ci[2]);
		ap_int<512> H[3];
		H[1] = GetH();
		H[2] = GetH();
		H[3] = GetH();
		for (int i = 0; i < 3; i++)
		{
			H[i] = H[i] - h[i];
		}
		Auth.token = token_create();
		ap_int<512> m = Gost(Auth.token);
		Elliptic C = (Ci[0] + Ci[1] + Ci[2] + Ci[3]);
		ap_int<512> R = C.x % q;
		MultiAuthElliptic Auth;
		for (int i = 0; i < 3; i++)
		{
			Auth.s[i] = k[i] * m + R * a[i];
		}
	    frn:mult(Auth.s*,H*, Connect);
		Auth.key = R;
		return Auth;
	}

};
