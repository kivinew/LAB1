/* Вариант № 9. Комплексные числа.
Объект класса хранит действительную ( REAL a ) и мнимую ( IMAGE b*i ) часть комплексного числа z = a + b*i.
Предусмотреть методы вычисления модуля ( вектора ) и аргумента ( угла ).
*/

#include "comPlex.h"
#include <locale>
#include <Windows.h>
#define ESC 27
#define SPACEBAR 32
#define ONE 49
#define TWO 50
#define ENTER 13
#define DEL 46

void menu(Complex** &, int);
Complex** grow(Complex**, int &);

int main()
{
    setlocale(LC_ALL, "russian");
    SetCursorPos(600, 0);
    SetConsoleTitleA("LAB1: Complex numbers");

    Complex** arrPointers;                                  // объявление массива указателей
    int arrSize;                                            // размер массива

    cout<<"Введите количество объектов: ";
    cin>>arrSize;

    arrPointers = new Complex*[arrSize]();                  // определение массива

    system("cls");
    do
    {
        menu(arrPointers, arrSize);
    } while (1);
    return 0;
    delete[] arrPointers;
}

void menu(Complex** &objectArray, int size)                 // вывод таблицы объектов и меню
{
    int objNumber;
    char choice;

    system("cls");
    cout<<"Объект :\t"<<"Модуль :\t"<<"Аргумент :\t"<<endl;
    for (int i = 0; i<size; i++)  // таблица объектов
    {
        if (objectArray[i]!=NULL)
        {
            cout<<i<<": ";
            (objectArray[i])->showObject();
        }
        else
            cout<<"empty"<<endl;
    }
    cout<<"\n\tSPACEBAR - обновить"<<endl                   // меню
        <<"\t1 - добавить объект со своими параметрами"<<endl
        <<"\t2 - добавить объект"<<endl
        <<"\tENTER - выбрать для работы один объект"<<endl
        <<"\tESC - выход"<<endl;
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
        case ONE:
        {
            for (int i = 0; i<size; i++)
            {
                if (objectArray[i]==NULL)                   // если указатель нулевой, то
                {                                           // ввести значения полей объекта
                    objectArray[i] = new Complex;
                    objectArray[i]->edit();
                    return; // break; ?
                }

            }
            break;
        }
        case TWO:
        {
            objectArray = grow(objectArray, size);
            break;
        }
        case ENTER:
        {
            cout<<"Укажите номер объекта: ";
            cin>>objNumber;
            int countObjects = objectArray[0]->getCounter();
            if (!(objNumber>=size)&&!(objNumber<0))
            {
                if (countObjects!=0)
                {
                    cout<<"DELETE - удалить объект"<<endl
                        <<"ENTER- редактировать объект"<<endl
                        <<"SPACEBAR - скопировать объект"<<endl
                        <<"ESC - отмена"<<endl;
                    while (!_kbhit());
                    choice = _getch();
                    switch (choice)
                    {
                    case DEL:
                        objectArray[objNumber]->del(objectArray[objNumber]);
                        break;
                    case ENTER:
                        objectArray[objNumber]->edit();
                        break;
                    case SPACEBAR:                          // настроить конструктор копирования!!!!!!!

                        break;
                    case ESC:
                        break;
                    }
                }
                else
                {
                    cout<<"Массив пуст! Создай объект."<<endl;
                    _getch();
                }
            }
            else
            {
                cout<<"Выход за пределы массива!";
                _getch();
            }
            break;
        }
        case ESC:
            exit(0);
            break;
    }
    return;
}

Complex** grow(Complex** arr, int &size)                    // увеличение массива указателей в два раза
{
    Complex** newArr;                                       // новый массив
    size *= 2;
    newArr = new Complex*[size];                            // размером counter*2
    for (int i = 0; i<size; i++)
    {
        newArr[i] = NULL;
    }
    delete arr;
    cout<<size<<endl;
    return newArr;
}