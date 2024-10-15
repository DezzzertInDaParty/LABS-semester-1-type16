#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	float x, y, up, down, res, x2, x3;
	cout << "Введите число: ";
	cin >> x;
	x2 = pow(x, 2);
	x3 = pow(x, 3);
	up = x * (1 + x2) - 3; //Числитель
	down = 2 * x * (x - 2) + 2 * x3 * (3 - 2* x2) + 2; //Знаменатель
	y = up / down;
	res = (x + pow(x, 3) - 3) / (2 * pow(x, 2) - 4 * x + 2 + 6 * pow(x, 3) - 4 * pow(x, 5)); //Общая формула
	cout << y << "  " << res << endl;
}