#include "comPlex.h"

int comPlex::counter = 0;

comPlex::comPlex(): real(0), image(counter++)                           // конструктор по умолчанию
{
}

comPlex::comPlex(int re, int im)                                        // конструктор с параметрами
{
    real = re;
    image = im;
    counter++;
}

comPlex::comPlex(comPlex &obj)                                          // конструктор копирования
{
    this->real = obj.real;
    this->image = obj.image;
    counter++;
}

comPlex::~comPlex()                                                     // деструктор
{
    cout<<"Удалён объект "<<counter--<<endl;
    delete this;
}

int comPlex::getCounter()                                               // вывод счётчика
{
    return counter;
}

bool comPlex::entering()                                                // ввод членов комплексного числа
{
    double tmpReal, tmpImage;                                           // временные переменные для проверки на ноль
    cout<<"Введите действительную часть Z: real= ";                     // действительная часть
    cin>>tmpReal;
    cout<<"Введите мнимую часть Z: image= ";                            // мнимая часть
    cin>>tmpImage;
    cout<<endl;

    if (tmpReal==0&&tmpImage==0)
    {
        cout<<"|Z| = 0 "<<endl;
        cout<<"Аргумент не определён!!!"<<endl;
        _getch();
        return false;
    }
    real = tmpReal;
    image = tmpImage;
    return true;
}

void comPlex::showObject(comPlex* ptr)                                  // вывод объектов
{
    cout<<"Z="<<ptr->real<<"+"<<ptr->image<<"*i"<<"\t\t";
    cout<<"|Z|="<<ptr->mod()<<"\t";
    cout<<"arg Z="<<ptr->arg()<<"\t"<<endl;
    return;
}

double comPlex::mod()                                                   // модуль
{
    return sqrt(real*real+image*image);
}

double comPlex::arg()                                                   // аргумент
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
