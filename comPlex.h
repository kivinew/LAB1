#pragma once
#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

class Complex
{
    const double pi = 3.141592654;
    static int counter;
    double real, image;
public:
    Complex();
    Complex(int, int);
    Complex(Complex &);
    ~Complex();
    int getCounter();
    void entering();
    Complex** grow(Complex**);
    void edit();
    void del(Complex*);
    void showObject();
    double mod();
    double arg();
};
