/* Вариант № 9. Комплексные числа.
Объект класса хранит действительную ( REAL a ) и мнимую ( IMAGE bi ) часть комплексного числа z = a + bi.
Предусмотреть методы вычисления модуля ( вектора ) и аргумента ( угла ).
*/

#include "comPlex.h"

void main ( )
{
    comPlex *Z = new comPlex();
    double r , i;
    printf ( "Enter real and image parts of complex: " );           // действительная и мнимая части
    scanf_s ( "%f" , &r , &i);
    Z->real ( r );


    return ;
}

