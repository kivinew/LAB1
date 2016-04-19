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

Complex::Complex(Complex &obj)                              // конструктор копировани€
{
    counter++;
    real = obj.real;
    image = obj.image;
}

Complex::~Complex()                                         // деструктор
{
    cout<<"ќбъект "<<counter--<<" удалЄн"<<endl;    
}

int Complex::getCounter()                                   // возврат счЄтчика
{
    return counter;
}

void Complex::edit()                                        // редактирование объекта
{
    cout<<"¬ведите действительную часть Z: real= "<<endl;
    cin>>real;
    cout<<"¬ведите мнимую часть Z: image= "<<endl;
    cin>>image;
    return;
}

void Complex::del(Complex* &obj)                            // удаление указател€ на объект
{
    obj = NULL;
    return;
}

void Complex::showObject()                                  // вывод объектов
{
    cout<<"Z="<<real<<"+"<<image<<"*i"<<"\t"<<"|Z|="<<mod()<<"\t";
    if (arg()!=0) 
        cout<<"arg Z="<<arg()<<"\t"<<endl;
    else 
        cout<<"n/a"<<endl;
    return;
}

double Complex::mod()                                       // модуль
{
    return sqrt(real*real+image*image);
}

double Complex::arg()                                       // аргумент
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
