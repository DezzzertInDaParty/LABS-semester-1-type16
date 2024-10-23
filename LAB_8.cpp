#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	float x, z, y1, y2, y3;
	cout << "Введите значение X: ";
	cin >> x;
	cout << endl;
	if (x < 0) { z = -1; }
	if (x > 0) { z = 1; }
	if (x == 0) { z = 0; }
	// Алгоритм 1
	if (abs(x) <= 1) { y1 = z * (abs(x) - 1); }
	else if (abs(x) <= 2) { y1 = 0; }
	else { y1 = -1*z; }
	cout << "Программа 1:" << endl;
	cout << "Y1 = " << y1 << endl;
	cout << endl;
	// Алгоритм 2
	if (abs(x) <= 1) { y2 = z * (abs(x) - 1); }
	if (abs(x) > 1 and abs(x) <= 2) { y2 = 0; }
	if (abs(x) > 2) { y2 = -1 * z; }
	cout << "Программа 2:" << endl;
	cout << "Y2 = " << y2 << endl;
	cout << endl;
	// Алгоритм 3
	y3 = (abs(x) <= 1) ? z * (abs(x) - 1) : (abs(x) <= 2) ? y3 = 0 : y3 = -1 * z;
	cout << "Программа 3:" << endl;
	cout << "Y3 = " << y3 << endl;
}
