#pragma once
#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

class Complex
{
    static double const pi ;
    static int counter;
    double real, image;
    int num;
public:
    Complex();
    Complex(int, int);
    Complex(Complex &);
    ~Complex();

    static int getCounter();
    static void edit(Complex*);
    void del(Complex* &);
    void showObject();
    double mod();
    double arg();
};
