/* ������� � 9. ����������� �����.
������ ������ ������ �������������� ( REAL a ) � ������ ( IMAGE bi ) ����� ������������ ����� z = a + bi.
������������� ������ ���������� ������ ( ������� ) � ��������� ( ���� ).
*/

#include "comPlex.h"

void main ( )
{
    comPlex *Z = new comPlex();
    double r , i;
    printf ( "Enter real and image parts of complex: " );           // �������������� � ������ �����
    scanf_s ( "%lf%lf" , &r , &i);
    Z->real ( r );
    Z->image ( i );
    printf ( "%lf\n" , Z->mod ( ) );
    _getch ( );
    return ;
}

