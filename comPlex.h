#pragma once
#include <math.h>
#include <cstdio>
#include <iostream>
#include <conio.h>

using namespace std;

class comPlex
{
    double re , im;
public:
    const double pi = 3.141592654;
    comPlex ( );
    comPlex ( char a );
    void real ( double );
    void image ( double );
    double mod ( );
    double arg ( );
};