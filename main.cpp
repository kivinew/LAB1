/* ������� � 9. ����������� �����.
������ ������ ������ �������������� ( REAL a ) � ������ ( IMAGE b*i ) ����� ������������ ����� z = a + b*i.
������������� ������ ���������� ������ ( ������� ) � ��������� ( ���� ).
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
    cout<<"������� ���������� ��������: ";
    cin>>objCount;

    Complex *objArr = new Complex[objCount];                        // ������ ��������
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
    cout<<"������ :\t"<<"������ :\t"<<"�������� :\t"<<endl;
    for (int i = 0; i<(objectArray->getCounter()); i++)
    {
        cout<<i;
        objectArray->showObject(objectArray+i);
    }
    cout<<"\n\tSPACEBAR - ����� ������� ��������"<<endl;
    cout<<"\t1 - �������� ������ �� ������ �����������"<<endl;
    cout<<"\t2 - �������� ������"<<endl;
    cout<<"\tENTER - ������� ��� ������ ���� ������"<<endl;
    cout<<"\tESC - �����"<<endl;
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
        cout<<"������� ����� �������: ";
        cin>>objNumber;
        if (!(objNumber>(objectArray->getCounter()))&&!(objNumber<0))
        {
            //objectArray->showObject(objectArray+objNumber);
            cout<<"DELETE - ������� ������"<<endl;
            cout<<"ENTER- ������������� ������"<<endl;
            cout<<"SPACEBAR - ����������� ������"<<endl;
            cout<<"ESC - ������"<<endl;
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
                Complex *objArr = new Complex (&objectArray);           // ��������� ����������� �����������!!!!!!!
                break;
            case ESC:
                break;
            }
        }
        else cout<<"������ ������� ���!";
        break;
    }
    case ESC:
        exit(0);
        break;
    }
    return;
}