#include <iostream>
#include"ap/ap.hpp"
using namespace std;
#include <stdlib.h>
#include <cstdio>
#include <memory.h>
#include <math.h>
#include "stribog/calc.h"
#include "stribog/gosttest.h"
#include "MultiAuth.h"
typedef unsigned char byte;



TGOSTHashContext* CTX;
static void
HashPrint(TGOSTHashContext* CTX)
{
    printf("%d bit hash sum: \n", CTX->hash_size);
    int i;
    if (CTX->hash_size == 256)
        for (i = 32; i < 64; i++)
            printf("%02x", CTX->hash[i]);
    else
        for (i = 0; i < 64; i++)
            printf("%02x", CTX->hash[i]);
    printf("\n");
}
static void
GetHashString(const char* str, int hash_size)
{
    uint8_t* buffer;
    buffer = malloc(strlen(str));
    memcpy(buffer, str, strlen(str));
    GOSTHashInit(CTX, hash_size);
    GOSTHashUpdate(CTX, buffer, strlen(str));
    GOSTHashFinal(CTX);
    printf("GOST 34.11-2012 \"Stribog\"\nString: %s\n", str);
    HashPrint(CTX);
}

static void
GetHashTest()
{
    printf("GOST 34.11-2012 \"Stribog\"\nTest String: "
        "012345678901234567890123456789012345678901234567890123456789012\n");
    GOSTHashInit(CTX, 512);
    GOSTHashUpdate(CTX, test_string, sizeof test_string);
    GOSTHashFinal(CTX);
    HashPrint(CTX);
    GOSTHashInit(CTX, 256);
    GOSTHashUpdate(CTX, test_string, sizeof test_string);
    GOSTHashFinal(CTX);
    HashPrint(CTX);
}