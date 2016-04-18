/* ������� � 9. ����������� �����.
������ ������ ������ �������������� ( REAL a ) � ������ ( IMAGE b*i ) ����� ������������ ����� z = a + b*i.
������������� ������ ���������� ������ ( ������� ) � ��������� ( ���� ).
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

    Complex** arrPointers;                                  // ���������� ������� ����������
    int arrSize;                                            // ������ �������

    cout<<"������� ���������� ��������: ";
    cin>>arrSize;

    arrPointers = new Complex*[arrSize]();                  // ����������� �������

    system("cls");
    do
    {
        menu(arrPointers, arrSize);
    } while (1);
    return 0;
    delete[] arrPointers;
}

void menu(Complex** &objectArray, int size)                 // ����� ������� �������� � ����
{
    int objNumber;
    char choice;

    system("cls");
    cout<<"������ :\t"<<"������ :\t"<<"�������� :\t"<<endl;
    for (int i = 0; i<size; i++)  // ������� ��������
    {
        if (objectArray[i]!=NULL)
        {
            cout<<i<<": ";
            (objectArray[i])->showObject();
        }
        else
            cout<<"empty"<<endl;
    }
    cout<<"\n\tSPACEBAR - ��������"<<endl                   // ����
        <<"\t1 - �������� ������ �� ������ �����������"<<endl
        <<"\t2 - �������� ������"<<endl
        <<"\tENTER - ������� ��� ������ ���� ������"<<endl
        <<"\tESC - �����"<<endl;
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
                if (objectArray[i]==NULL)                   // ���� ��������� �������, ��
                {                                           // ������ �������� ����� �������
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
            cout<<"������� ����� �������: ";
            cin>>objNumber;
            int countObjects = objectArray[0]->getCounter();
            if (!(objNumber>=size)&&!(objNumber<0))
            {
                if (countObjects!=0)
                {
                    cout<<"DELETE - ������� ������"<<endl
                        <<"ENTER- ������������� ������"<<endl
                        <<"SPACEBAR - ����������� ������"<<endl
                        <<"ESC - ������"<<endl;
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
                    case SPACEBAR:                          // ��������� ����������� �����������!!!!!!!

                        break;
                    case ESC:
                        break;
                    }
                }
                else
                {
                    cout<<"������ ����! ������ ������."<<endl;
                    _getch();
                }
            }
            else
            {
                cout<<"����� �� ������� �������!";
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

Complex** grow(Complex** arr, int &size)                    // ���������� ������� ���������� � ��� ����
{
    Complex** newArr;                                       // ����� ������
    size *= 2;
    newArr = new Complex*[size];                            // �������� counter*2
    for (int i = 0; i<size; i++)
    {
        newArr[i] = NULL;
    }
    delete arr;
    cout<<size<<endl;
    return newArr;
}