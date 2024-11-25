#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	float epsilon, x0, Nmax;
	float n = 0, n2 = 0;
	cout << "Введите количество максимальных итераций N: ";
	cin >> Nmax;
	cout << endl << "Введите начальное приближение x0: ";
	cin >> x0;
	cout << endl << "Введите значение точности E: ";
	cin >> epsilon;
	cout << endl;
	// Метод простых итераций
	float x1, diff;
	do
	{
		x1 = -1 * ((log(x0 / 3)));
		diff = x1 - x0;
		x0 = x1;
		n++;
	} while (abs(diff) > epsilon and n < Nmax);
	cout << "Метод простых итераций" << endl;
	if (n < Nmax)
	{
		cout << "X = " << x1 << endl;
	}
	else
	{
		cout << "Превышен лимит операций" << endl;
	}
	cout << endl;
	// Метод касательных
	if ((x0 + log(x0 / 3) * (-1 / (x0 * x0))) > 0)
	{
		do
		{
			x1 = x0 - ((x0 + log(x0 / 3)) / (1 + (1 / x0)));
			x0 = x1;
			n2++;
		} while (abs(x0 - x1) > epsilon and n2 < Nmax);
	}
	cout << "Метод касательных" << endl;
	if (n2 < Nmax)
	{
		cout << "X = " << x1 << endl;
	}
	else
	{
		cout << "Превышен лимит операций" << endl;
	}
}
