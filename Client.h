#pragma once
#include <iostream>
#include"ap/ap.hpp"
#include"ap/ap.hpp"
using namespace std;
#include <stdlib.h>
#include <cstdio>
#include <memory.h>
#include <math.h>
#include "stribog/calc.h"
#include "stribog/gosttest.h"
#include "MultiAuth.h"
#include "MultiSign.h"
#include "MultiSignElliptic.h"
#include "MultiAuthElliptic.h"
#include <sstream>
#include"Elliptic.hpp"

class SekretH
{
public:
	ap_int<512> H1;
	ap_int<512> H2;
	ap_int<512> H3;
	ap_int<512> H4;

	ap_int<512> Random()
	{
		ap_int<512> S1 = 0;
		ap_int<512> S2 = 0;
		int random = 0;
		for (int i = 0; i < 512; i += 32)
		{
			random = rand()%(2^32);
			S2 = random;
			S1 += S2 * (2 ^ i);
		}
		return S1;
	}
	SekretH Sharing(ap_int<512> H, ap_int<512> q)
	{
		SekretH sekretH;
		sekretH.H1 = Random();
		sekretH.H2 = Random();
		sekretH.H3 = Random();
		sekretH.H4 = (H - H1 - H2 - H3 + 3 * q) % q;
		return sekretH;
	}
	ap_int<512> DeSharing(ap_int<512> H1, ap_int<512> H2, ap_int<512> H3, ap_int<512> H4, ap_int<512> q)
	{
		H1 = (H1 + H2 + H3 + H4) % q;
		return H1;
	}
	ap_int<512> inv(ap_int<512> i, ap_int<512> m) {
		return i <= 1 ? i : m - (ap_int<512>)(m / i) * inv(m % i) % m;
	}
	int Cheek(ap_int<512> S1, ap_int<512> S2, ap_int<512> S3, ap_int<512> S4, string M, ap_int<512> q, ap_int<512> R)
	{
		ap_int<512> m = Gost(M);
		ap_int<512> e = m % q;
		if (e == 0)
		{
			e = 1;
		}
		ap_int<512> v = inv(e, q);
		S1 = DeSharing(S1, S2, S3, S4, q);
		ap_int<512> z1 = (S1 * v) % q;
		ap_int<512> z2 = -1 * ((R * v) % q);
		Elliptic C = pointE(z1, z2);
		ap_int<512> R2 = pointX(C);
		R2 = R2 % q;
		if (R2 == R)
			return 0;
		return 1;
	}
	string AuthP(string Password, ap_int<512> q)
	{
		ap_int<512> h = Gost(Password);
		SekretH H = Sharing(h, q);

	}
	string AuthT(string token)
	{

	}
};

