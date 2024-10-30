#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	float x, y1, y2, p, q;
	cout << "Введите значение X: ";
	cin >> x;
	cout << endl;
	p = cos(x);
	q = log(3 - pow(p, 2));
	// Вычисление 1
	y1 = (p * q - (2 * p - 2 * pow(p, 3)) / (3 - pow(p, 2))) / pow(q, 2);
	cout << "Вычисление 1: " << y1 << endl;
	// Вычисление 2
	float up, down;
	up = cos(x) * log(2 + pow(sin(x), 2)) - ((2 * pow(sin(x), 2) * cos(x)) / (2 + pow(sin(x), 2)));
	down = pow(log(2 + pow(sin(x), 2)), 2);
	y2 = up / down;
	cout << "Вычисление 2: " << y2 << endl;
	cout << endl << endl;
	// Вычисление в цикле
	cout << "Приращение dX" << "\t    " << "Производная" << "\t\t" << "Абс. ошибка" << "\t   " << "Относ. ошибка" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	float dx = 0.0005;
	float dx1, dx2, dy1, dy2, dy, derivative, abs_diff, relative;
	while (dx <= 0.017)
	{
		dx1 = x + (dx / 2);
		dx2 = x - (dx / 2);
		dy1 = sin(dx1)/ log(2 + pow(sin(dx1), 2)); // Y(x + dx/2)
		dy2 = sin(dx2) / log(2 + pow(sin(dx2), 2)); // Y(x - dx/2)
		dy = dy1 - dy2;
		derivative = dy / dx;
		abs_diff = abs(derivative - y2);
		relative = (abs_diff / y2) * 100;
		cout << dx << "\t\t     " << derivative << "\t\t" << abs_diff << "\t   " << relative << " %" << endl;
		dx = dx * 2;
	}
}
