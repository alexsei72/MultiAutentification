#include "Token_create.h"
#include <iostream>
using namespace std;

//данный раздел должен быть переопределен для генерации токенов.

    string folder = "ew0KICAiYWxnIjogIkdPU1QiLA0KICAidHlwIjogIkpXVCINCn0";
	string header = "eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkpvaG4gRG9lIiwiYWRtaW4iOnRydWUsImlhdCI6MTUxNjIzOTAyMn0";
	string token_create()
	{
		return folder + "." + header;
	}


