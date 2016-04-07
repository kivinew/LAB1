#include "comPlex.h"

void comPlex::menu()
{
    int i = 0;
    int choice;
    system("cls");
    cout<<"0 - ����� ������� ��������"<<endl;
    cout<<"1 - ������� ������ �� ������ �����������"<<endl;
    cout<<"2 - ������� ������ � ����������� �� ���������"<<endl;
    cout<<"3 - ���������� ��������� ��������"<<endl;
    cin>>choice;
    switch (choice)
    {
        case 0:
        {
            cout<<"������ :\t"<<"������ :\t"<<"�������� :\t"<<endl;
            for (i = 0; i<10; i++)
            {
                showObject(this+i);
            }
            _getch();
            break;
        }
        case 1:
        {
            system("cls");
            if (this->entering())
            {
                this->showObject(this);
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

            break;
        }
    }
    return;
}

comPlex::comPlex(): real(0), image(1)                                   // ����������� �� ���������
{
    counter++;
}

comPlex::comPlex(int re, int im)                                        // ����������� � �����������
{
    real = re;
    image = im;
    counter++;
}

comPlex::~comPlex()                                                     // ����������
{
    system("cls");
    counter--;
}

int comPlex::getCounter()                                               // ����� ��������
{
    return counter;
}

bool comPlex::entering()                                                // ���� ������ ������������ �����
{
    double tmpReal, tmpImage;                                           // ��������� ���������� ��� �������� �� ����
    cout<<"������� �������������� ����� Z: real= ";                     // �������������� �����
    cin>>tmpReal;
    cout<<"������� ������ ����� Z: image= ";                            // ������ �����
    cin>>tmpImage;
    cout<<endl;

    if (tmpReal==0&&tmpImage==0)
    {
        cout<<"|Z| = 0 "<<endl;
        cout<<"�������� �� ��������!!!"<<endl;
        _getch();
        return false;
    }
    real = tmpReal;
    image = tmpImage;
    return true;
}

void comPlex::showObject(comPlex* ptr)                                  // ����� ��������
{
    cout<<"Z="<<ptr->real<<"+"<<ptr->image<<"*i"<<"\t\t";
    cout<<"|Z|="<<ptr->mod()<<"\t";
    cout<<"arg Z="<<ptr->arg()<<"\t"<<endl;
    return;
}

double comPlex::mod()                                                   // ������
{
    return sqrt(real*real+image*image);
}

double comPlex::arg()                                                   // ��������
{
    if (real>0) return atan(image/real);
    if (real<0)
    {
        if (image>0) return pi+atan(image/real);
        if (image<0) return -pi+atan(image/real);
        if (image==0) return pi;
    }
    if (real==0)
    {
        if (image>0) return pi/2;
        if (image<0) return -pi/2;
    }
    return 0;
}
