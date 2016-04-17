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

void menu(Complex**, int);

int main()
{
    setlocale(LC_ALL, "russian");
    SetCursorPos(600, 0);
    SetConsoleTitleA("LAB1: Complex numbers");

    int objCount;
    cout<<"������� ���������� ��������: ";
    cin>>objCount;

    Complex** arrPointers;
    arrPointers = new Complex*[objCount];                           // ������ ���������� �� �������
    for (int i=0; i<objCount;i++)
    {
        arrPointers[i] = new Complex;
    }
    _getch();
    system("cls");
    do
    {
        menu(arrPointers, objCount);
    } while (1);
    return 0;
    delete[] arrPointers;
}

void menu(Complex** objectArray, int countObjects)                  // ����� ������� �������� � ����
{
    int objNumber, i;
    char choice;
    system("cls");
    cout<<"������ :\t"<<"������ :\t"<<"�������� :\t"<<endl;
    for (i = 0; i<(objectArray[0]->getCounter()); i++)              // ������� ��������
    {
        cout<<i<<": ";
        (objectArray[i])->showObject();
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
        case ONE:
        {
            objectArray = objectArray[i-1]->grow(objectArray);
            countObjects = objectArray[i]->getCounter();
            objectArray[i]->entering();
            break;
        }
        case TWO:
        {
            objectArray = objectArray[i-1]->grow(objectArray);

            break;
        }
        case ENTER:
        {
            cout<<"������� ����� �������: ";
            cin>>objNumber;
            if (!(objNumber>=(objectArray[0]->getCounter()))&&!(objNumber<0))
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
                    objectArray[objNumber]->del(objectArray[objNumber]);
                    break;
                case ENTER:
                    objectArray[objNumber]->edit();
                    break;
                case SPACEBAR:                                      // ��������� ����������� �����������!!!!!!!
                    if(i>=objectArray[0]->getCounter())
                        objectArray[0]->grow(objectArray);
                    new Complex* (objectArray[i]);
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
