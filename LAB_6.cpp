#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	float cons, x1, x2, y1, y2;
	cout << "Введите значение С: ";
	cin >> cons;
	// x2 + 2xc + c2 = 1 - x2/4 - приравниваем уравнения кривых
	// (x2 + x2/4) + 2cx + (c2 - 1) = 0
	// 5/4 x2 + 2cx + c2 - 1 = 0
	// 5x2 + 8xc + 4c2 - 4 = 0 - выражение для поиска общих абцисс
	float a = 5;
	float b = 8 * cons;
	float c = 4 * pow(cons, 2) - 4;
	float discriminant = pow(b, 2) - 4 * a * c;
	x1 = ((- b) - sqrt(discriminant)) / (2 * a);
	x2 = ((- b) + sqrt(discriminant)) / (2 * a);
	y1 = x1 + cons;
	y2 = x2 + cons;
	cout << "(X1, Y1) = " << "(" << x1 << ", " << y1 << ")" << endl;
	cout << "(X2, Y2) = " << "(" << x2 << ", " << y2 << ")" << endl;
	cout << endl << "ПРОВЕРКА" << endl;
	cout << "(x1/2)^2 + y1^2 = ";
	cout << pow((x1 / 2), 2) + pow(y1, 2) << endl;
	cout << "y1 = x1 + C = ";
	cout << x1 + cons << endl;
	cout << "(x2/2)^2 + y2^2 = ";
	cout << pow((x2 / 2), 2) + pow(y2, 2) << endl;
	cout << "y2 = x2 + C = ";
	cout << x2 + cons << endl;
}