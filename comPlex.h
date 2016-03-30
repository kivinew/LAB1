#pragma once
#include <math.h>
#include <cstdio>
#include <iostream>

using namespace std;

class comPlex
{
    double re , im;
public:
    comPlex ( );
    ~comPlex ( );
    void real ( double );
    void image ( double );
    double mod ( );
    double arg ( );
};

