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
#define CREATE_DEFAULT 50
#define ENTER 13
#define DEL 46

void menu(Complex*, int);

int main()
{
    setlocale(LC_ALL, "russian");
    SetCursorPos(600, 0);
    SetConsoleTitleA("LAB1: Complex numbers");

    int objCount;
    cout<<"������� ���������� ��������: ";
    cin>>objCount;

    Complex* arrPtr;
    arrPtr = new Complex[objCount];                                 // ������ ��������
    system("cls");
    do
    {
        menu(arrPtr, objCount);
    } while (1);
    return 0;
    delete[] arrPtr;
}

void menu(Complex *objectArray, int countObjects)                   // ����� ������� �������� � ����
{
    int objNumber, i;
    char choice;
    system("cls");
    cout<<"������ :\t"<<"������ :\t"<<"�������� :\t"<<endl;
    for (i = 0; i<(objectArray->getCounter()); i++)                 // ������� ��������
    {
        cout<<i;
        objectArray->showObject(objectArray+i);
    }
    cout<<"\n\tSPACEBAR - ��������"<<endl;                          // ����
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
            (objectArray+i)->entering();
            break;
        }
        case CREATE_DEFAULT:
        {
            if (i>=objectArray->getCounter())
                (objectArray+i)->grow(objectArray);
            break;
        }
        case ENTER:
        {
            cout<<"������� ����� �������: ";
            cin>>objNumber;
            if (!(objNumber>=(objectArray->getCounter()))&&!(objNumber<0))
            {
                cout<<"DELETE - ������� ������"<<endl;
                cout<<"ENTER- ������������� ������"<<endl;
                cout<<"SPACEBAR - ����������� ������"<<endl;
                cout<<"ESC - ������"<<endl;
                while (!_kbhit());
                choice = _getch();
                switch (choice)
                {
                case DEL:
                    objectArray[objNumber].del();
                    break;
                case ENTER:
                    objectArray[objNumber].edit();
                    break;
                case SPACEBAR:                                      // ��������� ����������� �����������!!!!!!!
                    if(i>=objectArray->getCounter())
                        (objectArray)->grow(objectArray);
                    new Complex* (objectArray+i);
                    break;
                case ESC:
                    break;
                }
            }
            else cout<<"������ ������� ���!";
            _getch();
            break;
        }
        case ESC:
            exit(0);
            break;
    }
    return;
}
