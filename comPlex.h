#pragma once
#include <math.h>
#include <cstdio>
#include <iostream>
#include <conio.h>

using namespace std;

class comPlex
{
    static int counter ;
    double real , image;
    long long int big [ 50000 ];
public:
    const double pi = 3.141592654;
    comPlex ( );
    ~comPlex ( );
    bool entering ( );
    double mod ( );
    double arg ( );
};