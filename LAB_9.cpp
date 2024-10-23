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

}
