#include "comPlex.h"

comPlex::comPlex() : real(1), image(1)                                                    // ����������� �� ���������
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

bool comPlex::entering()                                              // ���� ������ ������������ �����
{
	double tmpReal, tmpImage;                                          // ��������� ���������� ��� �������� �� ����
	cout << "Enter real part of complex number Z: real= ";             // �������������� �����
	cin >> tmpReal;
	cout << "Enter image part of complex number Z: image= ";           // ������ �����
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
    cout << "������ :" << "\t" << i;
    cout << "������ :" << comPlex::mod ( ) ;
    cout << "�������� :" << comPlex::arg ( );
}

double comPlex::mod()                                             // ������
{
	return sqrt(real*real + image*image);
}

double comPlex::arg()                                             // ��������
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
