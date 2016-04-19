/* ������� � 9. ����������� �����.
������ ������ ������ �������������� ( REAL a ) � ������ ( IMAGE b*i ) ����� ������������ ����� z = a + b*i.
������������� ������ ���������� ������ ( ������� ) � ��������� ( ���� ).
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
static void createObj(Complex** &, int &);
void showTable(Complex** &, int);

int main()
{
    setlocale(LC_ALL, "Ru");
    SetCursorPos(600, 0);
    SetConsoleTitleA("LAB1: Complex numbers");

    Complex** arrPointers;                                  // ���������� ������� ����������
    int arrSize;                                            // ������ �������

    cout<<"������� ���������� ��������: ";
    cin>>arrSize;
    if (arrSize==0) 
        arrSize = 1;
    arrPointers = new Complex*[arrSize]();                  // ����������� �������

    system("cls");
    do
    {
        menu(arrPointers, arrSize);
    } while (1);
    delete[] arrPointers;
    return 0;
}

void menu(Complex** &objectArray, int &size)                 // ����� ������� �������� � ����
{
    int objNumber;
    int choice;
    system("cls");

    showTable(objectArray, size);

    cout<<"\n\tSPACEBAR - ��������"<<endl                   // ����
        <<"\t1 - �������� ������"<<endl
        <<"\t2 - ����������� ������"<<endl
        <<"\tENTER - ������� ��� ������ ���� ������"<<endl
        <<"\tESC - �����"<<endl;
    while (!_kbhit());
    choice = _getch();
    switch (choice)
    {
        case SPACEBAR:
        {
            break;
        }
        case ONE:
        {
            createObj(objectArray, size);
            break;
        }
        case TWO:
        {

            break;
        }
        case ENTER:
        {
            cout<<"������� ����� �������: ";
            cin>>objNumber;

            int countObjects = objectArray[0]->getCounter();        // ���������� �������� � �������
            if (!(objNumber>=size) && !(objNumber<0))
            {
                if (countObjects!=0)                                // ������ � ������� ���� ���������� ������� �� ����� ����
                {
                    cout<<endl
                        <<"DELETE - ������� ������"<<endl
                        <<"ENTER- ������������� ������"<<endl
                        <<"SPACEBAR - ����������� ������"<<endl
                        <<"��� ������ ������� ����� ������ �������"<<endl;
                    while (!_kbhit());

                    choice = _getch();                      // ���������� ������!!!  1) �������� ������
                    choice = _getch();                      //                       2) �������� ��� �������
                    
                    switch (choice)
                    {

                    case DEL:                                       // �������� ��������� �� ������                             !!!
                        objectArray[0]->del(objectArray[objNumber]);// ������� ����� del() ��� �������� �������                 !!!
                        break;                                      // � ������� � ���� ��������� �� ��������� ������           !!!

                    case ENTER:                                     // �������� ������
                        if (objectArray[objNumber]!=NULL)           // ���� ��������� �� ����� ����
                            objectArray[objNumber]->edit();         // �� ��� ����� ��������,
                        else                                        //
                            createObj(objectArray, size);           // � ����� �������
                        break;
                    case SPACEBAR:                                  // ��������� ����������� �����������                        !!!
                        //copy();
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
            for (int i = 0; i<size; i++)
            {
                delete objectArray[i];                      // �������� �������� �������
                objectArray[i] = NULL;                      // � ��������� ����������
            }
            delete[] objectArray;                           // �������� �������
            cout<<"������ �����"<<endl;
            _getch();
            exit(0);                                        // ����� �� ���������
            break;
    }
    return;
}

void grow(Complex** &arr, int &size)                // ���������� ������� ���������� � ��� ����
{
    int newSize;                                    // ����� ������ �������
    newSize = size*2;
    Complex** newArr;                               // ����� ������
    newArr = new Complex*[newSize];
    for (int i = 0; i<newSize; i++)
    {
        if (i<size)                                 // �������� ��������� ������� �������
            newArr[i] = arr[i];                     // ����������� ��������� ������
        else
            newArr[i] = NULL;                       
    }
    delete [] arr;                                  // ����� ������ ������
    arr = newArr;                                   // � ��� ��������� �������� �����
    size = newSize;
    return ;
}

void createObj(Complex** &objectArray, int &size)
{
    if (objectArray[0]->getCounter()==size)         // ���� ���������� �������� ����� ������� �������
        grow(objectArray, size);                    // �� ��� ����� ���������
    for (int i = 0; i<size; i++)
    {
        if (objectArray[i]==NULL)                           // ���� ��������� �������, ��
        {                                                   // 
            objectArray[i] = new Complex();                 // ������� � ���� ������ ������
            
            return;
        }
    }
    return;
}

void showTable(Complex** &arr, int size)
{
    cout<<"������ :\t"<<"������ :\t"<<"�������� :\t"<<endl;
    for (int i = 0; i<size; i++)                            // ������� ��������
    {
        cout<<i<<": ";
        if (arr[i]!=NULL)                                   // ���� ��������� �� ����� ����
        {
            (arr[i])->showObject();                         // �� ������� ������
        }
        else
            cout<<"empty"<<endl;
    }
}