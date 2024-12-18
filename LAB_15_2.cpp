#include <iostream>
#include <cstring>
using namespace std;

unsigned long long copy_counter = 0;
unsigned long long compare_counter = 0;

struct person
{
    string surname;
    string name;
    string patronymic;
    int number;
};

void InsertionSort(person arr[], int size) 
{
    for (int i = 1; i < size; i++) 
    {
        person key = arr[i];
        int j = i - 1;
        compare_counter++;
        while (j >= 0 and key.number > arr[j].number) 
        {
            arr[j + 1] = arr[j];
            copy_counter++;
            j--;
        }

        arr[j + 1] = key;
        copy_counter++;
    }
}

void InputArray(person array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        string first, second, third;
        int num;
        cout << "Введите " << i + 1 << " элемент: ";
        cin >> first;
        cin >> second;
        cin >> third;
        cin >> num;
        array[i].surname = first;
        array[i].name = second;
        array[i].patronymic = third;
        array[i].number = num;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    person* array{ new person[n] };
    InputArray(array, n);
    InsertionSort(array, n);
    cout << endl << "Отсротированный массив:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i].surname << " ";
        cout << array[i].name << " ";
        cout << array[i].patronymic << " ";
        cout << array[i].number << endl;
    }
    cout << endl;
    cout << "Количество операций копирования: " << copy_counter << endl;
    cout << "Количество операций сравнения: " << compare_counter << endl;

}
