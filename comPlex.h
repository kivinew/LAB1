#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

static int counter;
class comPlex
{
    double real, image;
public:
    const double pi = 3.141592654;
    comPlex();
    comPlex(int, int);
    ~comPlex();
    void menu();
    int getCounter();
    bool entering();
    void showObject(comPlex*);
    double mod();
    double arg();
};