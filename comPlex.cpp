#include "comPlex.h"

int Complex::counter = 0;
double const Complex::pi = 3.1415926536;

Complex::Complex(): real(1), image(1)                       // конструктор по умолчанию
{
    num = counter++;                                        // добавлю поле с номером объекта
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
    cout<<"ДЕСТРУКТОР: "<<counter--<<" объект "<<" удалён"<<endl;
}

int Complex::getCounter()                                   // возврат счётчика
{
    return counter;
}

void Complex::edit(Complex* obj)                                        // редактирование объекта
{
    cout<<endl<<"РЕДАКТОР: Введите действительную часть Z: real= "<<endl;
    cin>>obj->real;
    cout<<"РЕДАКТОР: Введите мнимую часть Z: image= "<<endl;
    cin>>obj->image;
    return;
}

void Complex::del(Complex* &obj)                            // удаление указателя на объект
{
    if (obj!=NULL)
    {
        obj = NULL;
        counter--;
    }
    else
    {
        cout<<"Объекта нет!"<<endl;
        _getch();
    }
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
