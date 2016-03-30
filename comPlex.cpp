#include "comPlex.h"

comPlex::comPlex ( )
{
    re = 0;
    im = 0;
}

comPlex::~comPlex ( )
{
}

void comPlex::real ( double Real )                                   // действительная часть 
{
    re = Real;
    return;
}

void comPlex::image ( double Image )                                 // мнимая часть 
{
    im = Image;
    return;
}

double comPlex::mod ( )
{
    return sqrt ( re*re + im*im );
}

double comPlex::arg ( )
{
    return 0.0;
}
