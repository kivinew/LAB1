#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

class Complex
{
    static int counter;
    double real, image;
public:
    const double pi = 3.141592654;
    Complex();
    Complex(int, int);
    Complex::Complex(Complex &);
    ~Complex();
    int getCounter();
    void entering();
    void edit();
    void del();
    void showObject(Complex*);
    double mod();
    double arg();
};