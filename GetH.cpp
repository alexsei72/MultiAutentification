#include "GetH.h"
#include <iostream>
#include"ap/ap.hpp"
using namespace std;
// Модуль для извлечения хэша из базы данных
ap_int<512> GetH()
{
	ap_int<512> H{ "b79465edbb2036fa2cb1f488c01747ab1b808939ac2973d275968c38b00254d2" };
	return H;
}
