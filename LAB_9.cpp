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
	// Вычисление 2
	float up, down;
	up = cos(x) * log(2 + pow(sin(x), 2)) - (2 * pow(sin(x), 2) * cos(x)) / (2 + pow(sin(x), 2));
	down = pow(log(2 + pow(sin(x), 2)), 2);
	y2 = up / down;
	// Вычисление в цикле
	cout << "dX" << "        " << "dY/dX" << "        " << "|(dY/dX)-Y'|" << endl;
	for (float dx = 0.0005; dx <= 0.016; dx = dx * 2)
	{
		float dx1 = x + dx / 2, dx2 = x - dx / 2;
		float dy1_up = cos(dx1) * log(2 + pow(sin(dx1), 2)) - (2 * pow(sin(dx1), 2) * cos(dx1)) / (2 + pow(sin(dx1), 2));
		float dy1_down = pow(log(2 + pow(sin(dx1), 2)), 2);
		float dy1 = dy1_up / dy1_down;
		float dy2_up = cos(dx2) * log(2 + pow(sin(dx2), 2)) - (2 * pow(sin(dx2), 2) * cos(dx2)) / (2 + pow(sin(dx2), 2));
		float dy2_down = pow(log(2 + pow(sin(dx2), 2)), 2);
		float dy2 = dy2_up / dy2_down;
		float dy = dy1 - dy2;
		float derivative = dy / dx;
		float abs_diff = abs(derivative - y2);
		cout << dx << "     " << derivative << "     " << abs_diff << endl;
	}

}
