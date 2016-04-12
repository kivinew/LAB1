/* Вариант № 9. Комплексные числа.
Объект класса хранит действительную ( REAL a ) и мнимую ( IMAGE b*i ) часть комплексного числа z = a + b*i.
Предусмотреть методы вычисления модуля ( вектора ) и аргумента ( угла ).
*/

#include "comPlex.h"
#include <locale>
#include <Windows.h>
#define ESC 27
#define SPACEBAR 32
#define CREATE_CUSTOM 49
#define CREATE_DEFAULT 116
#define ENTER 13
#define DEL 46

void menu(Complex*, int);

void main()
{
    setlocale(LC_ALL, "russian");
    SetCursorPos(600, 0);
    SetConsoleTitleA("LAB1: Complex numbers");

    int objCount;
    cout<<"Введите количество объектов: ";
    cin>>objCount;

    Complex *objArr = new Complex[objCount];                        // массив объектов
    system("cls");
    do
    {
        menu(objArr, objCount);
    } while (1);
    return;
}

void menu(Complex *objectArray, int countObjects)
{
    int objNumber;
    char choice;
    system("cls");
    cout<<"Объект :\t"<<"Модуль :\t"<<"Аргумент :\t"<<endl;
    for (int i = 0; i<(objectArray->getCounter()); i++)
    {
        cout<<i;
        objectArray->showObject(objectArray+i);
    }
    cout<<"\n\tSPACEBAR - вывод массива объектов"<<endl;
    cout<<"\t1 - добавить объект со своими параметрами"<<endl;
    cout<<"\t2 - добавить объект"<<endl;
    cout<<"\tENTER - выбрать для работы один объект"<<endl;
    cout<<"\tESC - выход"<<endl;
    while (!_kbhit())
    {
    }
    choice = _getch();
    switch (choice)
    {
    case SPACEBAR:
    {
        system("cls");
        break;
    }
    case CREATE_CUSTOM:
    {
        objectArray->entering();
        break;
    }
    case CREATE_DEFAULT:
    {
        
        break;
    }
    case ENTER:
    {
        cout<<"Укажите номер объекта: ";
        cin>>objNumber;
        if (!(objNumber>(objectArray->getCounter()))&&!(objNumber<0))
        {
            //objectArray->showObject(objectArray+objNumber);
            cout<<"DELETE - удалить объект"<<endl;
            cout<<"ENTER- редактировать объект"<<endl;
            cout<<"SPACEBAR - скопировать объект"<<endl;
            cout<<"ESC - отмена"<<endl;
            while (!_kbhit());
            choice = _getch();
            switch (choice)
            {
            case DEL:
                (objectArray+objNumber)->del();
                break;
            case ENTER:
                (objectArray+objNumber)->edit();
                break;
            case SPACEBAR:
                Complex *objArr = new Complex (&objectArray);           // настроить конструктор копирования!!!!!!!
                break;
            case ESC:
                break;
            }
        }
        else cout<<"Такого объекта нет!";
        break;
    }
    case ESC:
        exit(0);
        break;
    }
    return;
}