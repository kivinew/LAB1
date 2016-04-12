#include "comPlex.h"

int comPlex::counter = 0;

comPlex::comPlex(): real(0), image(counter++)                           // ����������� �� ���������
{
}

comPlex::comPlex(int re, int im)                                        // ����������� � �����������
{
    real = re;
    image = im;
    counter++;
}

comPlex::comPlex(comPlex &obj)                                          // ����������� �����������
{
    this->real = obj.real;
    this->image = obj.image;
    counter++;
}

comPlex::~comPlex()                                                     // ����������
{
    cout<<"����� ������ "<<counter--<<endl;
    delete this;
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
