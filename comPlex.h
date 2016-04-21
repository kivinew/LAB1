#pragma once
#include <iostream>
#include <conio.h>
#include <math.h>
#ifdef _DEBUG
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#endif
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
    void edit();
    void del(Complex* &);
    void showObject();
    double mod();
    double arg();
};
