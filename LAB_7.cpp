#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	float x;
	cout << "Введите значение X: ";
	cin >> x;
	cout << endl;
	int y1, y2;
	if (abs(x) < 1) {
		y1 = 1;
	}
	else {
		if (abs(x) < 2) {
			y1 = -1;
		}
		else {
			y1 = 0;
		}
	}
	cout << "Программа 1:" << endl;
	cout << "Y1 = " << y1 << endl;
	cout << endl;

	if (abs(x) < 1) {
		y2 = 1;
	}
	if (abs(x) >= 1 and abs(x) < 2) {
		y2 = -1;
	}
	if (abs(x) >= 2) {
		y2 = 0;
	}
	cout << "Программа 2:" << endl;
	cout << "Y2 = " << y1 << endl;
}