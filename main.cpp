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
void createObj(Complex** &, int &, int number=0);
void showTable(Complex** &, int);
void deleteAll(Complex** &, int);

int main()
{
    setlocale(LC_ALL, "Ru");
    SetCursorPos(600, 0);
    SetConsoleTitleA("LAB1: Complex numbers");

    Complex** arrPointers;                                  // ���������� ������� ����������
    int arrSize;                                            // ������ �������

    cout<<"������� ���������� �������� (�� ����� 1): ";
    cin>>arrSize;
    if (arrSize==0)
        arrSize = 1;
    arrPointers = new Complex* [arrSize]();                   // ����������� �������

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
    int number;
    int choice;
    system("cls");

    showTable(objectArray, size);

        cout<<"\t1        - �������� ���� ������"<<endl                 // ����
            <<"\tENTER    - ������� ������� �������"<<endl
            <<"\tESC      - ����� �� ���������"<<endl;
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
            cout<<"������� ����� �������: ";
            cin>>number;
            int countObjects = Complex::getCounter();               // ���������� �������� � �������
            if (!(number>=size) && !(number<0))
            {
                cout<<endl<<"ENTER    - ������ ������ � ���� �������"<<endl;
                if (objectArray[number]!=NULL)
                {
                    cout<<"DELETE   - ������� ������"<<endl
                        <<"SPACEBAR - ����������� ������"<<endl;
                }
                cout<<"��� ������ ������� ����� ������ �������"<<endl;
                while (!_kbhit());

                choice = _getch();                                  // ���������� ������!!!  1) �������� ������
                choice = _getch();                                  //                       2) �������� ��� �������
                    
                switch (choice)
                {
                case ENTER:                                                 // �������� ������
                    if (objectArray[number]!=NULL)                          // ���� ��������� �� ����� ����
                        objectArray[number]->edit(objectArray[number]);     // �� ��� ����� ��������,
                    else                                                    //
                        createObj(objectArray, size, number);               // � ����� �������
                    break;

                case DEL:                                           // �������� ��������� �� ������                             !!!
                    objectArray[0]->del(objectArray[number]);       // ������� ����� del() ��� �������� �������                 !!!
                    break;                                          // � ������� � ���� ��������� �� ��������� ������           !!!

                case SPACEBAR:                                      // ��������� ����������� �����������                !!!
                    //copy();
                    break;
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
            deleteAll(objectArray, size);
            exit(0);                                // ����� �� ���������
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

void createObj(Complex** &objectArray, int &size, int elementNumber)
{
    if (Complex::getCounter()==size)                        // ���� ���������� �������� ����� ������� �������
        grow(objectArray, size);                            // �� ��� ����� ���������
    for (int i=elementNumber; i<size; i++)
	{
		if (objectArray[i]==NULL)                          	// ���� ��������� �������, ��
        {                                                   // 
            *(objectArray+i) = new Complex();               // ������� � ���� ������ ������
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
        cout<<i+1<<": ";
        if (arr[i]!=NULL)                                   // ���� ��������� �� ����� ����
        {
            (arr[i])->showObject();                         // �� ������� ������
        }
        else
            cout<<"empty"<<endl;
    }
}

void deleteAll(Complex** &arr, int size)
{
    for (int i = 0; i<size; i++)
    {
        delete arr[i];                      // �������� �������� �������
    }
    delete[] arr;                           // �������� �������
    cout<<"������ �����"<<endl;
    _getch();
    return;
}