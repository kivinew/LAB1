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
    scanf_s ( "%f" , &r , &i);
    Z->real ( r );


    return ;
}

