/* ������� � 9. ����������� �����.
������ ������ ������ �������������� ( REAL a ) � ������ ( IMAGE b*i ) ����� ������������ ����� z = a + b*i.
������������� ������ ���������� ������ ( ������� ) � ��������� ( ���� ).
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
    int choice;
    cout<<"\n\t0 - ����� ������� ��������"<<endl;
    cout<<"\t1 - ������� ������ �� ������ �����������"<<endl;
    cout<<"\t2 - ������� ������ � ����������� �� ���������"<<endl;
    cout<<"\t3 - ������� ��� ������ ���� ������"<<endl;
    cout<<"��� �����: ";
    while (!_kbhit())
    {
        choice = _getch();
    }
    switch (choice)
    {
    case 0:
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
        cout<<"������� ����� �������: ";
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