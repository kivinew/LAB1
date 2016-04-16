#include "comPlex.h"

int Complex::counter = 0;

Complex::Complex(): real(0), image(0)                                   // конструктор по умолчанию
{
    counter++;
}

Complex::Complex(int re, int im): real(re), image(im)                   // конструктор с параметрами
{
    counter++;
}

Complex::Complex(const Complex &obj)                                    // конструктор копировани€
{
    counter++;
    this->real = obj.real;
    this->image = obj.image;
}

Complex::~Complex()                                                     // деструктор
{
    counter--;
}

int Complex::getCounter()                                               // вывод счЄтчика
{
    return counter;
}

void Complex::entering()                                                // ввод членов комплексного числа
{
    cout<<"¬ведите действительную часть Z: real= ";                     // действительна€ часть
    cin>>real;
    cout<<"¬ведите мнимую часть Z: image= ";                            // мнима€ часть
    cin>>image;
    cout<<endl;
    return;
}

void Complex::grow(Complex* arr)
{
    Complex* newArr;
    newArr = new Complex[counter*2];
    for (int i=0; i<counter; i++)
    {
        Complex newArr ( arr[i]);
    }
}

void Complex::edit()                                                    // редактирование объекта
{
    cout<<"¬ведите значение действительной части:"<<endl;
    cin>>this->real;
    cout<<"¬ведите значение мнимой части:"<<endl;
    cin>>this->image;
}

void Complex::del()                                                     // удаление объекта
{
    this->image = real = 0;
    delete this;
}

void Complex::showObject(Complex* ptr)                                  // вывод объектов
{
    cout<<"Z="<<ptr->real<<"+"<<ptr->image<<"*i"<<"\t";
    cout<<"|Z|="<<ptr->mod()<<"\t";
    if (ptr->arg()!=0) cout<<"arg Z="<<ptr->arg()<<"\t"<<endl;
    else cout<<"n/a"<<endl;
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
