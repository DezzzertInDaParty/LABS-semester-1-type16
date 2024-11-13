#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Локальные максимумы функции (x, y):" << endl;
	float min_derivative = pow(10, 10), x0, x1, x2, y0, y1, y2;
	float min_point;
	for (float x = -3.501; x < 5.5; x = x + 0.001)
	{
		x0 = x - 0.001;
		x1 = x;
		x2 = x + 0.001;
		y0 = pow(x0, 2) * (pow(sin(3 * x0), 3) - pow(cos(2 * x0), 2));
		y1 = pow(x1, 2) * (pow(sin(3 * x1), 3) - pow(cos(2 * x1), 2));
		y2 = pow(x2, 2) * (pow(sin(3 * x2), 3) - pow(cos(2 * x2), 2));
		if ((y1 > y0) and (y2 < y1))
		{
			cout << "(" << x1 << ", " << y1 << ")" << endl;
			min_derivative = min(min_derivative, abs(y2 - y1));
			if (abs(y2 - y1) == min_derivative)
			{
				min_point = x1;
			}
		}
	}
	cout << endl;
	cout << "Точка с минимальным значением производной: " << min_point << endl;
}
