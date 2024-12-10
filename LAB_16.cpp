#include <iostream>
using namespace std;

int fibonacciRecursive(int n) 
{
    if (n <= 1) 
    {
        return n;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int fibonacciSimple(int n) 
{
    if (n == 0) 
    {
        return 0;
    }
    int prev = 0;
    int curr = 1;
    for (int i = 1; i < n; ++i) 
    {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите номер члена ряда Фибоначчи: ";
    cin >> n;
    cout << "Рекурсивный метод: " << fibonacciRecursive(n) << endl;
    cout << "Обычный метод: " << fibonacciSimple(n) << endl;

    // Проверка правильности выполнения программ
    cout << endl << "Вывод ряда Фибоначчи в цикле (проверка)" << endl;
    cout << "Рекурсивный метод:\t";
    for (int i = 1; i <= 10; i++)
    {
        cout << fibonacciRecursive(i) << '\t';
    }
    cout << endl << "Обычный метод:\t\t";
    for (int i = 1; i <= 10; i++)
    {
        cout << fibonacciSimple(i) << '\t';
    }
    cout << "\n\n";
    return 0;
}
