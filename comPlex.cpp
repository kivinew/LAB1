#include "comPlex.h"

int Complex::counter = 0;

Complex::Complex(): real(0), image(2*counter++)             // ����������� �� ���������
{
}

Complex::Complex(int re, int im): real(re), image(im)       // ����������� � �����������
{
    counter++;
}

Complex::Complex(Complex &obj)                              // ����������� �����������
{
    counter++;
    real = obj.real;
    image = obj.image;
}

Complex::~Complex()                                         // ����������
{
    counter--;
}
int Complex::getCounter()                                   // ������� ��������
{
    return counter;
}

void Complex::entering()                                    // ���� ������ ������������ �����
{
    cout<<"������� �������������� ����� Z: real= ";         // �������������� �����
    cin>>real;
    cout<<"������� ������ ����� Z: image= ";                // ������ �����
    cin>>image;
    cout<<endl;
    return;
}

void Complex::edit()                                        // �������������� �������
{
    cout<<"������� �������� �������������� �����:"<<endl;
    cin>>real;
    cout<<"������� �������� ������ �����:"<<endl;
    cin>>image;
    return;
}

void Complex::del(Complex* ptr)                             // �������� �������
{
    delete ptr;
    return;
}

void Complex::showObject()                                  // ����� ��������
{
    cout<<"Z="<<real
        <<"+"<<image
        <<"*i"<<"\t"
        <<"|Z|="<<mod()
        <<"\t";
    if (arg()!=0) 
        cout<<"arg Z="<<arg()<<"\t"<<endl;
    else 
        cout<<"n/a"<<endl;
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
