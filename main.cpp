/* ������� � 9. ����������� �����.
������ ������ ������ �������������� ( REAL a ) � ������ ( IMAGE b*i ) ����� ������������ ����� z = a + b*i.
������������� ������ ���������� ������ ( ������� ) � ��������� ( ���� ).
*/

#include "comPlex.h"
#include <locale>
#include <Windows.h>

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
    cin>>choice;

    switch (choice)
    {
    case 0:
    {
        cout<<"������ :\t"<<"������ :\t"<<"�������� :\t"<<endl;
        for (int i = 0; i<countObjects; i++)
        {
            objectArray->showObject(objectArray+i);
        }
        _getch();
        break;
    }
    case 1:
    {
        system("cls");
        if ((objectArray+countObjects)->entering())
        {
            objectArray->showObject(objectArray);
        }
        else
        {
            system("cls");
            return;
        }
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
        (objectArray+objNumber)->showObject();
        break;
    }
    }
    return;
}