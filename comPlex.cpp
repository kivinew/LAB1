#include "comPlex.h"

comPlex::comPlex() : real(1), image(1)                                                    // конструктор по умолчанию
{
	counter++ ;
}

comPlex::comPlex ( int re , int im )
{
    real = re;
    image = im;
    counter++;
}

comPlex::~comPlex()
{
	system("cls");
	counter-- ;
}

int comPlex::getCounter()
{
	return counter;
}

bool comPlex::entering()                                              // ввод членов комплексного числа
{
	double tmpReal, tmpImage;                                          // временные переменные для проверки на ноль
	cout << "Enter real part of complex number Z: real= ";             // действительная часть
	cin >> tmpReal;
	cout << "Enter image part of complex number Z: image= ";           // мнимая часть
	cin >> tmpImage;
	cout << endl;

	if (tmpReal == 0 && tmpImage == 0)
	{
		cout << "Module |Z| is 0 " << endl;
		cout << "ARGUMENT IS NOT DEFINED!!!" << endl;
		_getch();
		return false;
	}
	real = tmpReal;
	image = tmpImage;
	return true;
}

void comPlex::show ( int i )
{
    cout << "Объект :" << "\t" << i;
    cout << "Модуль :" << comPlex::mod ( ) ;
    cout << "Аргумент :" << comPlex::arg ( );
}

double comPlex::mod()                                             // модуль
{
	return sqrt(real*real + image*image);
}

double comPlex::arg()                                             // аргумент
{
	if (real > 0) return atan(image / real);
	if (real < 0)
	{
		if (image > 0) return pi + atan(image / real);
		if (image < 0) return -pi + atan(image / real);
		if (image == 0) return pi;
	}
	if (real == 0)
	{
		if (image > 0) return pi / 2;
		if (image < 0) return -pi / 2;
	}
	return 0;
}
