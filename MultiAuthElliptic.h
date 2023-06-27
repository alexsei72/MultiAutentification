#pragma once
#include "MultiAuthElliptic.h"
#include "MultiSignElliptic.h"
#include <iostream>
#include"ap/ap.hpp"
#include"Pow.h"
#include"GetH.h"
#include "DEN22/src/frn.h"
#include "Token_create.h"
#include "Token_create.cpp"
using namespace std;
class MultiAuthElliptic
{
public:
	string token;
	ap_int<512> key;
	ap_int<512> s[3];
	MultiAuthElliptic MAuth(ap_int<512>[3], ap_int<512> [3], ap_int<512>, PRG)