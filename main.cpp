/* ������� � 9. ����������� �����.
������ ������ ������ �������������� ( REAL a ) � ������ ( IMAGE b*i ) ����� ������������ ����� z = a + b*i.
������������� ������ ���������� ������ ( ������� ) � ��������� ( ���� ).
*/

#include "comPlex.h"
#include <locale>
#include <Windows.h>
#define ESC 27
#define SHOW 48
#define CREATE_CUSTOM 49
#define CREATE_DEFAULT 50
#define SELECT_ONE 51

void menu(comPlex*, int);

void main()
{
    setlocale(LC_ALL, "russian");
    SetCursorPos(600, 0);
    SetConsoleTitleA("LAB1: complex numbers");

    int objCount;
    cout<<"������� ���������� ��������: ";
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
    char choice;
    cout<<"\n\t0 - ����� ������� ��������"<<endl;
    cout<<"\t1 - ������� ������ �� ������ �����������"<<endl;
    cout<<"\t2 - ������� ������ � ����������� �� ���������"<<endl;
    cout<<"\t3 - ������� ��� ������ ���� ������"<<endl;
    cout<<"\tESC - �����"<<endl;
    while (!_kbhit())
    {
    }
    choice = _getch();
    switch (choice)
    {
    case SHOW:
    {
        cout<<"������ :\t"<<"������ :\t"<<"�������� :\t"<<endl;
        for (int i = 0; i<countObjects; i++)
        {
            cout<<i;
            objectArray->showObject(objectArray+i);
        }
        cout<<"������� ����� �������...";
        _getch();
        break;
    }
    case CREATE_CUSTOM:
    {
        cout<<"1.........";
        _getch();
        break;
    }
    case CREATE_DEFAULT:
    {
        cout<<"2.........";
        _getch();
        break;
    }
    case SELECT_ONE:
    {
        cout<<"������� ����� �������: ";
        cin>>objNumber;
        if (!(objNumber>countObjects))
        {
            objectArray->showObject(objectArray+objNumber);
        }
        _getch();
        break;
    }
    case ESC:
        exit(0);
        break;
    }
    return;
}