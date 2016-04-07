#include "comPlex.h"

void comPlex::menu()
{
    int i = 0;
    int choice;
    system("cls");
    cout<<"0 - вывод массива объектов"<<endl;
    cout<<"1 - создать объект со своими параметрами"<<endl;
    cout<<"2 - создать объект с параметрами по умолчанию"<<endl;
    cout<<"3 - количество созданных объектов"<<endl;
    cin>>choice;
    switch (choice)
    {
        case 0:
        {
            cout<<"Объект :\t"<<"Модуль :\t"<<"Аргумент :\t"<<endl;
            for (i = 0; i<10; i++)
            {
                showObject(this+i);
            }
            _getch();
            break;
        }
        case 1:
        {
            system("cls");
            if (this->entering())
            {
                this->showObject(this);
            }
            else
            {
                system("cls");
                return;
            }
            _getch();
            break;
        }
        case 2:
        {

            break;
        }
        case 3:
        {

            break;
        }
    }
    return;
}

comPlex::comPlex(): real(0), image(1)                                   // конструктор по умолчанию
{
    counter++;
}

comPlex::comPlex(int re, int im)                                        // конструктор с параметрами
{
    real = re;
    image = im;
    counter++;
}

comPlex::~comPlex()                                                     // деструктор
{
    system("cls");
    counter--;
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
