#pragma once
#include <math.h>
#include <cstdio>
#include <iostream>
#include <conio.h>

using namespace std;

class comPlex
{
    double re , im, i ;
public:
    comPlex ( );
    ~comPlex ( );
    void real ( double );
    void image ( double );
    double mod ( );
    double arg ( );
};

