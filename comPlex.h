#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

class comPlex
{
    static int counter;
    double real, image;
public:
    const double pi = 3.141592654;
    comPlex();
    comPlex(int, int);
    comPlex::comPlex(comPlex &);
    ~comPlex();
    int getCounter();
    bool entering();
    void showObject(comPlex*);
    double mod();
    double arg();
};