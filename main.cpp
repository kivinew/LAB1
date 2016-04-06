/* Вариант № 9. Комплексные числа.
Объект класса хранит действительную ( REAL a ) и мнимую ( IMAGE b*i ) часть комплексного числа z = a + b*i.
Предусмотреть методы вычисления модуля ( вектора ) и аргумента ( угла ).
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
        cout << "Вариант создания объекта класса:" << endl;
        cout << "0 - создать объект с параметрами по умолчанию" << endl;
        cout << "1 - создать объект со своими параметрами" << endl;
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