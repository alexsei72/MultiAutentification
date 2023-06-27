#pragma once
#include "MultiAuth.h"
#include "MultiSign.h"
#include <iostream>
#include"ap/ap.hpp"
#include"Pow.h"
#include"GetH.h"
using namespace std;
#include "DEN22/src/frn.h"
#include "Token_create.h"
#include "Token_create.cpp"
class MultiAuth
{
public:
	string token;
	ap_int<512> key;
	ap_int<512> s[3];
	MultiAuth MAuth(ap_int<512>[3], ap_int<512> [3], ap_int<512> , ap_int<512> , ap_int<512> , PRG)