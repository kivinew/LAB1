#include "comPlex.h"

int Complex::counter = 0;

Complex::Complex(): real(0), image(counter++)                           // ����������� �� ���������
{
}

Complex::Complex(int re, int im): real(re), image(im)                   // ����������� � �����������
{
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
    //counter--;
}
int Complex::getCounter()                                               // ������� ��������
{
    return counter;
}

void Complex::entering()                                    // ���� ������ ������������ �����
{
    cout<<"������� �������������� ����� Z: real= ";                     // �������������� �����
    cin>>this->real;
    cout<<"������� ������ ����� Z: image= ";                            // ������ �����
    cin>>this->image;
    cout<<endl;
    return;
}

Complex** Complex::grow(Complex** arr)                                  // ���������� ������� ���������� � ��� ����
{
    Complex** newArr;
    newArr = new Complex*[counter*2];
    for (int i = 0; i<counter; i++)
    {
        Complex newObj(*arr[i]);
        newArr[i] = &newObj;
    }
    delete arr;
    return newArr;
}

void Complex::edit()                                                    // �������������� �������
{
    cout<<"������� �������� �������������� �����:"<<endl;
    cin>>this->real;
    cout<<"������� �������� ������ �����:"<<endl;
    cin>>this->image;
}

void Complex::del(Complex* ptr)                                                     // �������� �������
{
    this->image = real = 0;
    delete ptr;
}

void Complex::showObject()                                  // ����� ��������
{
    cout<<"Z="<<this->real<<"+"<<this->image<<"*i"<<"\t";
    cout<<"|Z|="<<this->mod()<<"\t";
    if (this->arg()!=0) cout<<"arg Z="<<this->arg()<<"\t"<<endl;
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
