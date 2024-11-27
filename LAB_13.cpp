#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	const int m1 = 3, n1 = 3;
	cout << "========= Обработка статического массива =========" << "\n\n";

	int D1[m1][n1]; // Создание статического массива
	for (int i = 0; i < m1; i++) // Ввод элементов массива
	{
		cout << "Введите элементы " << i + 1 << " строки: ";
		for (int j = 0; j < n1; j++)
		{
			int a;
			cin >> a;
			D1[i][j] = a;
		}
	}
	cout << endl;
	float mid1_g = 1, mid1_a = 0; // среднее геом. и арифм.
	for (int i = 0; i < m1; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			mid1_g = mid1_g * abs(D1[i][j]);
			mid1_a = mid1_a + abs(D1[i][j]);
		}
	}
	float num1 = m1 * n1;
	mid1_g = pow(mid1_g, (1 / num1));
	mid1_a = mid1_a / num1;
	cout << "Среднее геометрическое для статического массива (g): " << mid1_g << endl;
	cout << "Среднее арифметическое для статического массива (a): " << mid1_a << endl;
	cout << "\n";
	int arr_size1 = 0;
	for (unsigned i = 0; i < m1; i++) // Счет количества элементов между с.г. и с.а.
	{
		for (unsigned j = 0; j < n1; j++)
		{
			if ((D1[i][j] > mid1_g and D1[i][j] < mid1_a) or
				D1[i][j] < mid1_g and D1[i][j] > mid1_a)
			{
				arr_size1++;
			}
		}
	}
	int* elements1{ new int[arr_size1] };
	int count = 0;
	for (unsigned i = 0; i < m1; i++) // Заполнение массива элементов между с.г. и с.а.
	{
		for (unsigned j = 0; j < n1; j++)
		{
			if ((D1[i][j] > mid1_g and D1[i][j] < mid1_a) or
				D1[i][j] < mid1_g and D1[i][j] > mid1_a)
			{
				elements1[count] = D1[i][j];
				count++;
			}
		}
	}
	cout << "Вывод матрицы:" << endl;
	for (unsigned i = 0; i < m1; i++)
	{
		for (unsigned j = 0; j < n1; j++)
		{
			cout << D1[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << "Вывод чисел в интервале между g и a:" << endl;
	for (unsigned i = 0; i < arr_size1; i++)
		cout << elements1[i] << "\t";
	cout << "\n\n\n";
	

	cout << "========= Обработка динамического массива =========" << "\n\n";
	int m2, n2;
	cout << "Введите размер матрицы: ";
	cin >> m2 >> n2;
	int** D2{ new int*[m2] {} };
	for (int i = 0; i < n2; i++) // Создание динамического массивва
	{
		D2[i] = new int[n2] {};
	}
	for (int i = 0; i < m2; i++) // Ввод элементов массива
	{
		cout << "Введите элементы " << i + 1 << " строки: ";
		for (int j = 0; j < n2; j++)
		{
			int b;
			cin >> b;
			D2[i][j] = b;
		}
	}
	cout << endl;
	float mid2_g = 1, mid2_a = 0; // среднее геом. и арифм.
	for (int i = 0; i < m2; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			mid2_g = mid2_g * abs(D2[i][j]);
			mid2_a = mid2_a + abs(D2[i][j]);
		}
	}
	float num2 = m2 * n2;
	mid2_g = pow(mid2_g, (1 / num2));
	mid2_a = mid2_a / num2;
	cout << "Среднее геометрическое для динамического массива: " << mid2_g << endl;
	cout << "Среднее арифметическое для динамического массива: " << mid2_a << endl;
	cout << "\n";
	int arr_size2 = 0;
	for (unsigned i = 0; i < m2; i++) // Счет количества элементов между с.г. и с.а.
	{
		for (unsigned j = 0; j < n2; j++)
		{
			if ((D2[i][j] > mid2_g and D2[i][j] < mid1_a) or
				D2[i][j] < mid2_g and D2[i][j] > mid2_a)
			{
				arr_size2++;
			}
		}
	}
	int* elements2{ new int[arr_size2] };
	count = 0;
	for (unsigned i = 0; i < m2; i++) // Заполнение массива элементов между с.г. и с.а.
	{
		for (unsigned j = 0; j < n2; j++)
		{
			if ((D2[i][j] > mid2_g and D2[i][j] < mid2_a) or
				D2[i][j] < mid2_g and D2[i][j] > mid2_a)
			{
				elements2[count] = D2[i][j];
				count++;
			}
		}
	}
	cout << "Вывод матрицы:" << endl;
	for (unsigned i = 0; i < m2; i++)
	{
		for (unsigned j = 0; j < n2; j++)
		{
			cout << D2[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl << "Вывод чисел в интервале между g и a:" << endl;
	for (unsigned i = 0; i < arr_size2; i++)
		cout << elements2[i] << "\t";
	cout << "\n\n";
	return 0;
}
