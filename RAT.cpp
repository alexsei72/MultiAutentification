#include "Client.h"
#include <iostream>
#include "MultiSignElliptic.cpp"
#include "MultiAuthElliptic.h"
class RAT
{
public:
	MultiAuthElliptic Atoken;
	MultiAuthElliptic Rtoken;



	RAT Gettoken(ap_int<512> S1, ap_int<512> S2, ap_int<512> S3, ap_int<512> S4, string M, ap_int<512> q, ap_int<512> R, PRG Connect)
	{
		SekretH sekretH;
		int i = sekretH.Cheek(S1, S2, S3, S4, M, q, R);
		if (i == 0)
		{
			RAT Autn;
			RAT.MultiAuthElliptic AuthA;
			RAT.MultiAuthElliptic AuthB;
			AuthA.token = token_create();
			AuthB.token = token_create();
			ap_int<512> k[3] = GetRandomElement(Connect);
			Elliptic Ci[4];
			for (int i = 0; i < 3; i++)
			{
				Ci[i] = MultiSignElliptic(q, k[i]);
			}
			Ci[3] = Publication(Ci[0], Ci[1], Ci[2]);
			ap_int<512> mA = Gost(AuthA);
			ap_int<512> mB = Gost(AuthA);
			Elliptic C = (Ci[0] + Ci[1] + Ci[2] + Ci[3]);
			ap_int<512> R = C.x % q;
			for (int i = 0; i < 3; i++)
			{
				AuthA.s[i] = k[i] * mA + R * a[i];
			}
			for (int i = 0; i < 3; i++)
			{
				AuthB.s[i] = k[i] * mB + R * a[i];
			}
			frn:mult(AuthA.s*, H*, Connect);
			AuthA.key = R;
			AuthB.key = R;
			return Auth;

		}
	}
};