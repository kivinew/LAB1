/* ������� � 9. ����������� �����.
������ ������ ������ �������������� ( REAL a ) � ������ ( IMAGE b*i ) ����� ������������ ����� z = a + b*i.
������������� ������ ���������� ������ ( ������� ) � ��������� ( ���� ).
*/

#include "comPlex.h"
#include <locale>
#include <Windows.h>

void main ( )
{
    setlocale ( LC_ALL , "russian" );
    SetCursorPos ( 600 , 0 );
    SetConsoleTitleA ( "LAB1: complex numbers" );
    int i = 0;
    comPlex *Z = new comPlex [ 10 ];
    int choice;
    do
    {
        cout << "������� �������� ������� ������:" << endl;
        cout << "0 - ������� ������ � ����������� �� ���������" << endl;
        cout << "1 - ������� ������ �� ������ �����������" << endl;
        cin >> choice;

        if ( !choice )
        {
            ( Z + i )->comPlex::comPlex ( 1 , 1 );
            i++;
        }

        system ( "cls" );
        if ( Z->entering ( ) )
        {
            Z->show ( );
        }
        else
        {
            system ( "cls" );
            return;
        }
        _getch ( );
    } while ( 1 );
    return;
}