/* ������� � 9. ����������� �����.
������ ������ ������ �������������� ( REAL a ) � ������ ( IMAGE bi ) ����� ������������ ����� z = a + bi.
������������� ������ ���������� ������ ( ������� ) � ��������� ( ���� ).
*/

#include "comPlex.h"

void main ( )
{
    comPlex *Z = new comPlex();
    double r , i;
    do
    {
        system ( "cls" );
        cout << "Enter real part of complex number Z: Re= " ;            // �������������� �����
        cin >> r;
        cout << "Enter image part of complex number Z: Im= " ;         // ������ �����
        cin >> i;
        cout << endl;
        if ( r == 0 && i == 0 )
        {
            cout << "Module |Z| is 0 " << endl;
            cout << "ARGUMENT IS NOT DEFINED!!!" << endl; 
            _getch ( );
            return ;
        }
        Z -> real ( r );
        Z -> image ( i );
        cout << "Module |Z| is ..." << Z -> mod() << endl;
        cout << "Argument arg Z is ..." << Z -> arg() * 180 / Z -> pi << endl;
        _getch ( );
    } while ( 1 );
    return ;
}