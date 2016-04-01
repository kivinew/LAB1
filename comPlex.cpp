#include "comPlex.h"

comPlex::comPlex ( )                                                // ����������� �� ���������
{
    re = 0;
    im = 0;
}

comPlex::comPlex ( char a )
{

}

void comPlex::real ( double Real )                                  // �������������� ����� 
{
    re = Real;
    return;
}

void comPlex::image ( double Image )                                // ������ ����� 
{
    im = Image;
    return;
}

double comPlex::mod ( )                                             // ������
{
    return sqrt ( re*re + im*im );
}

double comPlex::arg ( )                                             // ��������
{
    if ( re > 0 ) return atan ( im / re );
    if ( re < 0 ) 
    {
        if ( im > 0 ) return pi + atan ( im / re );
        if ( im < 0 ) return -pi + atan ( im / re );
        if ( im == 0 ) return pi;
    }
    if ( re == 0 )
    {
        if ( im > 0 ) return pi / 2;
        if ( im < 0 ) return -pi / 2;
    }
    return 0;
}
