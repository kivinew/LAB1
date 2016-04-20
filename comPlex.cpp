#include "comPlex.h"

int Complex::counter = 0;

Complex::Complex(): real(255), image(255)                   // конструктор по умолчанию
{
    counter++;
}

Complex::Complex(int re, int im): real(re), image(im)       // конструктор с параметрами
{
    counter++;
}

Complex::Complex(Complex &obj)                              // конструктор копирования
{
    counter++;
    real = obj.real;
    image = obj.image;
}

Complex::~Complex()                                         // деструктор
{
    cout<<"Îáúåêò "<<counter--<<" óäàë¸í"<<endl;    
}

int Complex::getCounter()                                   // получить счётчик
{
    return counter;
}

void Complex::edit()                                        // редактирование объекта
{
    cout<<"Ââåäèòå äåéñòâèòåëüíóþ ÷àñòü Z: real= "<<endl;
    cin>>real;
    cout<<"Ââåäèòå ìíèìóþ ÷àñòü Z: image= "<<endl;
    cin>>image;
    return;
}

void Complex::del(Complex* &obj)                            // удалить указатель на объект из массива
{
    obj = NULL;
    return;
}

void Complex::showObject()                                  // вывод объекта
{
    cout<<"Z="<<real<<"+"<<image<<"*i"<<"\t"<<"|Z|="<<mod()<<"\t";
    if (arg()!=0) 
        cout<<"arg Z="<<arg()<<"\t"<<endl;
    else 
        cout<<"n/a"<<endl;
    return;
}

double Complex::mod()                                       // модуль |Z|
{
    return sqrt(real*real+image*image);
}

double Complex::arg()                                       // аргумент arg Z
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
