﻿/* Вариант № 9. Комплексные числа.
Объект класса хранит действительную ( REAL a ) и мнимую ( IMAGE b*i ) часть комплексного числа z = a + b*i.
Предусмотреть методы вычисления модуля ( вектора ) и аргумента ( угла ).
*/

#include "comPlex.h"
#define ESC         27
#define SPACEBAR    32
#define ONE         49
#define ENTER       13
#define DEL         83 

int menu(Complex** &, int &);
void grow(Complex** &, int &);
void createObj(Complex** &, int &, int number=0);
void createCopy(Complex** &, int &, int);
void showTable(Complex** &, int);
void deleteAll(Complex** &, int);

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleTitleA("LAB1: Complex numbers");

    Complex** arrPointers;                                                  // объявление массива указателей
    int arrSize;                                                            // размер массива
    cout<<"Введите количество объектов (не менее 1): ";
    cin>>arrSize;
    if (arrSize==0)
        arrSize = 1;
    arrPointers = new Complex* [arrSize]();                                 // определение массива
    system("cls");

    while (menu(arrPointers, arrSize)==TRUE);

    return 0;
}

int menu(Complex** &objectArray, int &size)                                 // вывод таблицы объектов и меню
{
    system("cls");
    showTable(objectArray, size);
        cout<<"\t1        - быстрая вставка объекта в пустую строку"<<endl	// меню
            <<"\tENTER    - выбрать элемент таблицы"<<endl
            <<"\tESC      - выход из программы"<<endl;
    while (!_kbhit());
    int choice;
    choice = _getch();
    switch (choice)
    {
        case ONE:                                                           // ---------вставить объект---------
        {
            createObj(objectArray, size);
            break;
        }
        case ENTER:                                                         // --------выбрать один элемент---------
        {
            int number;
            cout<<"Укажите номер строки: ";
            cin>>number;
            int countObjects = Complex::getCounter();                       // количество объектов в массиве
            if (!(number>=size) && !(number<0))
            {
                cout<<endl<<"ENTER    - ввести данные комплексного числа"<<endl;
                if (objectArray[number]!=NULL)
                {
                    cout<<"DELETE   - удалить комплексное число"<<endl
                        <<"SPACEBAR - скопировать комплексное число"<<endl;
                }
                cout<<"Для отмены нажмите любую другую клавишу"<<endl;
                while (!_kbhit());                                                  // ожидание выбора клавиши
                choice = _getch();                                                  // вызывается дважды!!!  1) получаем символ
                if (choice>83) choice = _getch();                                   //                       2) получаем код символа
                switch (choice)
                {
                case ENTER:                                                 // ------изменить объект-------
                    if (objectArray[number]!=NULL)                          // если указатель не равер нулю
                        objectArray[number]->edit();                        // то его можно изменить,
                    else                                                    //
                        createObj(objectArray, size, number);               // а иначе создать
                    break;
                case DEL:                                                   // --------удаление указателя на объект---------
                    Complex::del(objectArray[number]);
                    break;
                case SPACEBAR:                                              // --------настроить конструктор копирования---------
                    if (objectArray[number]!=NULL)
                        createCopy(objectArray, size, number);
                    break;
                }
            }
            else
            {
                cout<<"Выход за пределы массива!";
                _getch();
            }
            break;
        }
        case ESC:                                                           // ---------выход из программы---------
            deleteAll(objectArray, size);
            return FALSE;
            break;
    }
    return TRUE;
}

void grow(Complex** &arr, int &size)                // увеличение массива указателей в два раза
{
    int newSize;                                    // новый размер массива
    newSize = size*2;
    Complex** newArr;                               // новый массив
    newArr = new Complex*[newSize];
    for (int i = 0; i<newSize; i++)
    {
        if (i<size)                                 // значения элементов старого массива
            newArr[i] = arr[i];                     // присваиваем элементам нового
        else
            newArr[i] = NULL;                       
    }
    delete [] arr;                                  // удалён старый массив
    arr = newArr;                                   // и его указателю присвоен новый
    size = newSize;
    return ;
}

void createObj(Complex** &arr, int &size, int elementNumber)        // создать объект
{
    if (Complex::getCounter()==size)                                // если количество объектов равно размеру массива
        grow(arr, size);                                            // то его нужно увеличить
    for (int i=elementNumber; i<size; i++)
	{
		if (arr[i]==NULL)                          	                // если указатель нулевой, то
        {                                                           // 
            arr[i] = new Complex(-1, 1);                            // создать в этой ячейке объект
            return;
        }
	}
    return;
}

void createCopy(Complex** &arr, int &size, int elementToCopy)               // скопировать объект
{
    if (Complex::getCounter()==size)                                        // если количество объектов равно размеру массива
        grow(arr, size);                                                    // то его нужно увеличить
    for (int i = 0; i<size; i++)
    {
        if (arr[i]==NULL)                          	                        // если указатель нулевой, то
        {                                                                   // 
            arr[i] = new Complex(*arr[elementToCopy]);                      // создать в этой ячейке объект
            return;
        }
    }
    return;
}

void showTable(Complex** &arr, int size)                                    // вывод таблицы объектов
{
    cout<<"Объект :\t"<<"Модуль :\t"<<"Аргумент :\t"<<endl;
    for (int i = 0; i<size; i++)
    {
        cout<<i<<": ";
        if (arr[i]!=NULL)                                                   // если указатель не равен нулю
        {
            arr[i]->showObject();											// то выводим объект
        }
        else
            cout<<"empty"<<endl;
    }
}

void deleteAll(Complex** &arr, int size)                // удаление массива
{
    for (int i = 0; i<size; i++)
    {
        Complex::del(arr[i]);                           // удаление объектов массива
    }
    delete[] arr;                                       // удаление массива
    cout<<"Массив удалён"<<endl;
    _getch();
    return;
}
