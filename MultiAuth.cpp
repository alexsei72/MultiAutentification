#include "MultiAuth.h"
#include "MultiSign.h"
#include <iostream>
#include"ap/ap.hpp"
#include"Pow.h"
#include"GetH.h"
#include "DEN22/src/frn.h"
#include "Token_create.h"
#include "Token_create.cpp"
using namespace std;


class MultiAuth
{
public:
	string token;
	ap_int<512> key;
	ap_int<512> s[3];


	MultiAuth MAuth(string h, ap_int<512> a[3], ap_int<512> p, ap_int<512> q, ap_int<512> g, PRG Connect)
	{
		MultiAuth Auth;
		ap_int<512> k[3] = GetRandomElement(Connect);
		ap_int<512> Ri[4];
		for (int i = 0; i < 3; i++)
		{
			Ri[i] = MultiSign(a, p, q, g, k[i]);
		}
		Ri[3] = Publication(Ri[0], Ri[1], Ri[2]);
		ap_int<512> H[3];
		H[1] = GetH();
		H[2] = GetH();
		H[3] = GetH();
		for (int i = 0; i < 3; i++)
		{
			H[i] = H[i] - h[i];
		}//cheek
		Auth.token = token_create();
		ap_int<512> m = Gost(Auth.token);
		ap_int<512> R = (Ri[0] + Ri[1] + Ri[2] + Ri[3]) % q;
		MultiAuth Auth;
		for (int i = 0; i < 3; i++)
		{
			Auth.s[i] = k[i] * m + R * a[i];
		}
	frn:mult(Auth.s*, H*, Connect);
		Auth.key = R;
		return Auth;
	}

};
