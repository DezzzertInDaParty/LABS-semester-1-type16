#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите размер массива: ";
	cin >> n;
	float* d = new float[n];
	cout << "Введите элементы массива: " << endl;
	for (unsigned i{}; i < n; i++) // Ввод элементов массива
	{
		float element;
		cin >> element;
		d[i] = element;
	}
	cout << "Массив: ";
	float max_element = d[0], min_element = d[0];
	for (unsigned i{}; i < n; i++) // Поиск максимального и минимального элементов
	{
		if (d[i] > max_element)
			max_element = d[i];
		if (d[i] < min_element)
			min_element = d[i];
		cout << d[i] << " "; // Вывод массива
	}
	cout << endl;
	float half_sum = (max_element + min_element) / 2, A = 0, B = 0, C;
	for (unsigned i{}; i < n; i++) // Вычисление значений А и В
	{
		if (d[i] > half_sum)
			A = A + d[i];
		if (abs(d[i]) < half_sum)
			B = B + d[i];
	}
	C = A / B;
	cout << "Наибольший элемент: " << max_element << endl;
	cout << "Наименьший элемент: " << min_element << endl;
	cout << "A = " << A << "\t  B = " << B << endl;
	cout << "Результат: " << "C" << " = " << C << endl;
	delete[]d; // Освобождение памяти динамического массива d
	return 0;
}
