#include "comPlex.h"

int Complex::counter = 0;

Complex::Complex(): real(0), image(0)                                   // ����������� �� ���������
{
    counter++;
}

Complex::Complex(int re, int im)                                        // ����������� � �����������
{
    real = re;
    image = im;
    counter++;
}

Complex::Complex(Complex &obj)                                          // ����������� �����������
{
    counter++;
    this->real = obj.real;
    this->image = obj.image;
}

Complex::~Complex()                                                     // ����������
{
    counter--;
    cout<<"����� ������ "<<endl;
}

int Complex::getCounter()                                               // ����� ��������
{
    return counter;
}

void Complex::entering()                                                // ���� ������ ������������ �����
{
    double tmpReal, tmpImage;                                           // ��������� ���������� ��� �������� �� ����
    cout<<"������� �������������� ����� Z: real= ";                     // �������������� �����
    cin>>tmpReal;
    cout<<"������� ������ ����� Z: image= ";                            // ������ �����
    cin>>tmpImage;
    cout<<endl;
    real = tmpReal;
    image = tmpImage;
    return;
}

void Complex::edit()                                                    // �������������� �������
{
    cout<<"������� �������� �������������� �����:"<<endl;
    cin>>this->real;
    cout<<"������� �������� ������ �����:"<<endl;
    cin>>this->image;
}

void Complex::del()                                                     // �������� �������
{
    delete this;
}

void Complex::showObject(Complex* ptr)                                  // ����� ��������
{
    cout<<"Z="<<ptr->real<<"+"<<ptr->image<<"*i"<<"\t\t";
    cout<<"|Z|="<<ptr->mod()<<"\t";
    if (ptr->arg()!=0) cout<<"arg Z="<<ptr->arg()<<"\t"<<endl;
    else cout<<"n/a"<<endl;
    return;
}

double Complex::mod()                                                   // ������
{
    return sqrt(real*real+image*image);
}

double Complex::arg()                                                   // ��������
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
