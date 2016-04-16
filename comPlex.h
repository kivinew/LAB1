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
    Complex(const Complex &);
    ~Complex();
    int getCounter();
    void entering();
    void grow(Complex*);
    void edit();
    void del();
    void showObject(Complex*);
    double mod();
    double arg();
};
