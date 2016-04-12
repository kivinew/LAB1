/* Вариант № 9. Комплексные числа.
Объект класса хранит действительную ( REAL a ) и мнимую ( IMAGE b*i ) часть комплексного числа z = a + b*i.
Предусмотреть методы вычисления модуля ( вектора ) и аргумента ( угла ).
*/

#include "comPlex.h"
#include <locale>
#include <Windows.h>
#define ESC 27
void menu(comPlex*, int);

void main()
{
    setlocale(LC_ALL, "russian");
    SetCursorPos(600, 0);
    SetConsoleTitleA("LAB1: complex numbers");

    int objCount;
    cout<<"Введите количество объектов: ";
    cin>>objCount;
    comPlex *objArr = new comPlex[objCount];
    do
    {
        system("cls");
        menu(objArr, objCount);
    } while (1);
    return;
}

void menu(comPlex *objectArray, int countObjects)
{
    int objNumber;
    int choice;
    cout<<"\n\t0 - вывод массива объектов"<<endl;
    cout<<"\t1 - создать объект со своими параметрами"<<endl;
    cout<<"\t2 - создать объект с параметрами по умолчанию"<<endl;
    cout<<"\t3 - выбрать для работы один объект"<<endl;
    cout<<"Ваш выбор: ";
    while (!_kbhit())
    {
        choice = _getch();
    }
    switch (choice)
    {
    case 0:
    {
        cout<<"Объект :\t"<<"Модуль :\t"<<"Аргумент :\t"<<endl;
        for (int i = 0; i<countObjects; i++)
        {
            cout<<i;
            objectArray->showObject(objectArray+i);
        }
        cout<<"Нажмите любую клавишу...";
        _getch();
        break;
    }
    case 1:
    {
        
        _getch();
        break;
    }
    case 2:
    {

        break;
    }
    case 3:
    {
        cout<<"Укажите номер объекта: ";
        cin>>objNumber;
        objectArray->showObject(objectArray+objNumber);
        _getch();
        break;
    }
    case ESC:
        exit(0);
        break;
    }
    return;
}