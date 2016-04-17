#include "comPlex.h"

int Complex::counter = 0;

Complex::Complex(): real(0), image(counter++)                           // конструктор по умолчанию
{
}

Complex::Complex(int re, int im): real(re), image(im)                   // конструктор с параметрами
{
    counter++;
}

Complex::Complex(Complex &obj)                                          // конструктор копировани€
{
    counter++;
    this->real = obj.real;
    this->image = obj.image;
}

Complex::~Complex()                                                     // деструктор
{
    //counter--;
}
int Complex::getCounter()                                               // возврат счЄтчика
{
    return counter;
}

void Complex::entering()                                    // ввод членов комплексного числа
{
    cout<<"¬ведите действительную часть Z: real= ";                     // действительна€ часть
    cin>>this->real;
    cout<<"¬ведите мнимую часть Z: image= ";                            // мнима€ часть
    cin>>this->image;
    cout<<endl;
    return;
}

Complex** Complex::grow(Complex** arr)                                  // увеличение массива указателей в два раза
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

void Complex::edit()                                                    // редактирование объекта
{
    cout<<"¬ведите значение действительной части:"<<endl;
    cin>>this->real;
    cout<<"¬ведите значение мнимой части:"<<endl;
    cin>>this->image;
}

void Complex::del(Complex* ptr)                                                     // удаление объекта
{
    this->image = real = 0;
    delete ptr;
}

void Complex::showObject()                                  // вывод объектов
{
    cout<<"Z="<<this->real<<"+"<<this->image<<"*i"<<"\t";
    cout<<"|Z|="<<this->mod()<<"\t";
    if (this->arg()!=0) cout<<"arg Z="<<this->arg()<<"\t"<<endl;
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
