#include "comPlex.h"

int Complex::counter = 0;

Complex::Complex(): real(0), image(2*counter++)             // конструктор по умолчанию
{
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
    counter--;
}
int Complex::getCounter()                                   // возврат счЄтчика
{
    return counter;
}

void Complex::entering()                                    // ввод членов комплексного числа
{
    cout<<"¬ведите действительную часть Z: real= ";         // действительна€ часть
    cin>>real;
    cout<<"¬ведите мнимую часть Z: image= ";                // мнима€ часть
    cin>>image;
    cout<<endl;
    return;
}

void Complex::edit()                                        // редактирование объекта
{
    cout<<"¬ведите значение действительной части:"<<endl;
    cin>>real;
    cout<<"¬ведите значение мнимой части:"<<endl;
    cin>>image;
    return;
}

void Complex::del(Complex* ptr)                             // удаление объекта
{
    delete ptr;
    return;
}

void Complex::showObject()                                  // вывод объектов
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

double Complex::mod()                                                   // модуль
{
    return sqrt(real*real+image*image);
}

double Complex::arg()                                                   // аргумент
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
