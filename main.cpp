/* Вариант № 9. Комплексные числа.
Объект класса хранит действительную ( REAL a ) и мнимую ( IMAGE b*i ) часть комплексного числа z = a + b*i.
Предусмотреть методы вычисления модуля ( вектора ) и аргумента ( угла ).
*/

#include "comPlex.h"
#include <locale>
#include <Windows.h>
#define ESC         27
#define SPACEBAR    32
#define ONE         49
#define TWO         50
#define ENTER       13
#define DEL         83 

void menu(Complex** &, int &);
void grow(Complex** &, int &);
void createObj(Complex** &, int &, int number=0);
void showTable(Complex** &, int);
void deleteAll(Complex** &, int);

int main()
{
    setlocale(LC_ALL, "Ru");
    SetCursorPos(600, 0);
    SetConsoleTitleA("LAB1: Complex numbers");

    Complex** arrPointers;                                  // объявление массива указателей
    int arrSize;                                            // размер массива

    cout<<"Введите количество объектов (не менее 1): ";
    cin>>arrSize;
    if (arrSize==0)
        arrSize = 1;
    arrPointers = new Complex* [arrSize]();                   // определение массива

    system("cls");
    do
    {
        menu(arrPointers, arrSize);
    } while (1);
    delete[] arrPointers;
    return 0;
}

void menu(Complex** &objectArray, int &size)                 // вывод таблицы объектов и меню
{
    int number;
    int choice;
    system("cls");

    showTable(objectArray, size);

        cout<<"\t1        - вставить один объект"<<endl                 // меню
            <<"\tENTER    - выбрать элемент массива"<<endl
            <<"\tESC      - выход из программы"<<endl;
    while (!_kbhit());
    choice = _getch();
    switch (choice)
    {
        case ONE:
        {
            createObj(objectArray, size);
            break;
        }
        case ENTER:
        {
            cout<<"Укажите номер объекта: ";
            cin>>number;
            int countObjects = Complex::getCounter();               // количество объектов в массиве
            if (!(number>=size) && !(number<0))
            {
                cout<<endl<<"ENTER    - ввести данные в поля объекта"<<endl;
                if (objectArray[number]!=NULL)
                {
                    cout<<"DELETE   - удалить объект"<<endl
                        <<"SPACEBAR - скопировать объект"<<endl;
                }
                cout<<"Для отмены нажмите любую другую клавишу"<<endl;
                while (!_kbhit());

                choice = _getch();                                  // вызывается дважды!!!  1) получаем символ
                choice = _getch();                                  //                       2) получаем код символа
                    
                switch (choice)
                {
                case ENTER:                                                 // изменить объект
                    if (objectArray[number]!=NULL)                          // если указатель не равер нулю
                        objectArray[number]->edit(objectArray[number]);     // то его можно изменить,
                    else                                                    //
                        createObj(objectArray, size, number);               // а иначе создать
                    break;

                case DEL:                                           // удаление указателя на объект                             !!!
                    objectArray[0]->del(objectArray[number]);       // вызываю метод del() для нулевого объекта                 !!!
                    break;                                          // и передаю в него указатель на выбранный объект           !!!

                case SPACEBAR:                                      // настроить конструктор копирования                !!!
                    //copy();
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
        case ESC:
            deleteAll(objectArray, size);
            exit(0);                                // выход из программы
            break;
    }
    return;
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

void createObj(Complex** &objectArray, int &size, int elementNumber)
{
    if (Complex::getCounter()==size)                        // если количество объектов равно размеру массива
        grow(objectArray, size);                            // то его нужно увеличить
    for (int i=elementNumber; i<size; i++)
	{
		if (objectArray[i]==NULL)                          	// если указатель нулевой, то
        {                                                   // 
            *(objectArray+i) = new Complex();               // создать в этой ячейке объект
            return;
        }
	}
    return;
}

void showTable(Complex** &arr, int size)
{
    cout<<"Объект :\t"<<"Модуль :\t"<<"Аргумент :\t"<<endl;
    for (int i = 0; i<size; i++)                            // таблица объектов
    {
        cout<<i+1<<": ";
        if (arr[i]!=NULL)                                   // если указатель не равен нулю
        {
            (arr[i])->showObject();                         // то выводим объект
        }
        else
            cout<<"empty"<<endl;
    }
}

void deleteAll(Complex** &arr, int size)
{
    for (int i = 0; i<size; i++)
    {
        delete arr[i];                      // удаление объектов массива
    }
    delete[] arr;                           // удаление массива
    cout<<"Массив удалён"<<endl;
    _getch();
    return;
}