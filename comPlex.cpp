#include "comPlex.h"

int Complex::counter = 0;
double const Complex::pi = 3.1415926536;

Complex::Complex(): real(1), image(1)                       // ����������� �� ���������
{
    num = counter++;                                        // ������� ���� � ������� �������
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
    cout<<"����������: "<<counter--<<" ������ "<<" �����"<<endl;
}

int Complex::getCounter()                                   // ������� ��������
{
    return counter;
}

void Complex::edit(Complex* obj)                                        // �������������� �������
{
    cout<<endl<<"��������: ������� �������������� ����� Z: real= "<<endl;
    cin>>obj->real;
    cout<<"��������: ������� ������ ����� Z: image= "<<endl;
    cin>>obj->image;
    return;
}

void Complex::del(Complex* &obj)                            // �������� ��������� �� ������
{
    if (obj!=NULL)
    {
        obj = NULL;
        counter--;
    }
    else
    {
        cout<<"������� ���!"<<endl;
        _getch();
    }
    return;
}

void Complex::showObject()                                  // ����� ��������
{
    cout<<"Z="<<real<<"+"<<image<<"*i"<<"\t"<<"|Z|="<<mod()<<"\t";
    if (arg()!=0) 
        cout<<"arg Z="<<arg()<<"\t"<<endl;
    else 
        cout<<"n/a"<<endl;
    return;
}

double Complex::mod()                                       // ������
{
    return sqrt(real*real+image*image);
}

double Complex::arg()                                       // ��������
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
