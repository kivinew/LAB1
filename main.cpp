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

void menu(Complex**, int);
Complex** grow(Complex**);

int main()
{
    setlocale(LC_ALL, "russian");
    SetCursorPos(600, 0);
    SetConsoleTitleA("LAB1: Complex numbers");

    int arrSize;
    cout<<"Введите количество объектов: ";
    cin>>arrSize;

    Complex** arrPointers;
    arrPointers = new Complex*[arrSize];                           // массив указателей на объекты
    for (int i = 0; i<arrSize; i++)
    {
        arrPointers[i] = NULL;
    }
    _getch();
    system("cls");
    do
    {
        menu(arrPointers, arrSize);
    } while (1);
    return 0;
    delete[] arrPointers;
}

void menu(Complex** objectArray, int countObjects)                  // вывод таблицы объектов и меню
{
    int objNumber, i;
    char choice;
    system("cls");
    cout<<"Объект :\t"<<"Модуль :\t"<<"Аргумент :\t"<<endl;
    for (i = 0; i<(objectArray[0]->getCounter()); i++)              // таблица объектов
    {
        cout<<i<<": ";
        (objectArray[i])->showObject();
    }
    cout<<"\n\tSPACEBAR - обновить"<<endl;                          // меню
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
        case ONE:
        {
            objectArray = grow(objectArray);
            countObjects = objectArray[i]->getCounter();
            objectArray[i]->entering();
            break;
        }
        case TWO:
        {
            //objectArray = grow(objectArray);

            break;
        }
        case ENTER:
        {
            cout<<"Укажите номер объекта: ";
            cin>>objNumber;
            if (!(objNumber>=(objectArray[0]->getCounter()))&&!(objNumber<0))
            {
                cout<<"DELETE - удалить объект"<<endl;
                cout<<"ENTER- редактировать объект"<<endl;
                cout<<"SPACEBAR - скопировать объект"<<endl;
                cout<<"ESC - отмена"<<endl;
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
                case SPACEBAR:                                      // настроить конструктор копирования!!!!!!!
                    if(i>=objectArray[0]->getCounter())
                        grow(objectArray);
                    new Complex* (objectArray[i]);
                    break;
                case ESC:
                    break;
                }
            }
            else cout<<"Такого объекта нет!";
            _getch();
            break;
        }
        case ESC:
            exit(0);
            break;
    }
    return;
}

Complex** grow(Complex** arr)                                       // увеличение массива указателей в два раза
{
    int counter = arr[0]->getCounter();
    Complex** newArr;
    newArr = new Complex*[counter*2];
    for (int i = 0; i<counter; i++)
    {
        Complex newObj(**(arr+i));
        *(newArr+i) = &newObj;
    }
    delete arr;
    return newArr;
}