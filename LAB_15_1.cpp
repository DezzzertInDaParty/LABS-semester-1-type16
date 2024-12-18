#include <iostream>
using namespace std;

unsigned long long compare_counter = 0;
unsigned long long copy_counter = 0;

int findMinimumIndex(int input_data[], int start, int end) 
{
    int minIndex = start;
    for (int i = start; i <= end; i++) 
    {
        compare_counter++;
        if (input_data[i] < input_data[minIndex]) 
        {
            minIndex = i;
        }
    }
    return minIndex;
}

void swap(int &element1, int &element2) 
{
    int temp = element1;
    element1 = element2;
    element2 = temp;
}

// Сортировка выбором
void SelectionSort(int input_data[], int size)
{
    for (int i = 0; i < size; i++) 
    {
        int minIndex = findMinimumIndex(input_data, i, size - 1);
        swap(input_data[i], input_data[minIndex]);
        copy_counter += 3;
    }
}

// Пузырьковка сортиром
void BubbleUp(int input_data[], int start, int end, int &new_border)
{
    for (int i = start; i > end; i--)
    {
        compare_counter++;
        if (input_data[i] < input_data[i - 1])
        {
            swap(input_data[i], input_data[i - 1]);
            compare_counter += 3;
            new_border = i - 1;
        }
    }
}

void BubbleSort(int input_data[], int size)
{
    int current_border = 0;
    while (current_border < size) 
    {
        int new_border = size;
        BubbleUp(input_data, size - 1, current_border, new_border);
        current_border = new_border;
    }

}

// Сортировка вставками
int FindInsertionIndex(int input_array[], int left_index, int right_index) 
{
    int key = input_array[right_index];
    for (int i = left_index; i < right_index; i++) 
    {
        compare_counter++;
        if (input_array[i] > key) 
        {
            return i;
        }
    }
    return right_index;
}

void Insert(int input_array[], int left_index, int right_index) 
{
    int key = input_array[right_index];
    int insertion_index = FindInsertionIndex(input_array, left_index, right_index);
    for (int i = right_index; i > insertion_index; i--) 
    {
        input_array[i] = input_array[i - 1];
        copy_counter++;
    }

    input_array[insertion_index] = key;
    copy_counter++;;
}

void InsertionSort(int input_array[], int length) 
{
    for (int i = 1; i < length; i++) 
    {
        Insert(input_array, 0, i);
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите длину массива: ";
    cin >> n;
    int* array{ new int[n] };
    cout << "\n";
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++)
    {
        int elem;
        cin >> elem;
        array[i] = elem;

    }
    cout << "\n";

    cout << "Массив: ";
    for (int i = 0; i < n; ++i) 
    {
        cout << array[i] << ' ';
    }
    cout << "\n\n";

    SelectionSort(array, n);
    cout << "Сортировка выбором: ";
    for (int i = 0; i < n; ++i) 
    {
        cout << array[i] << ' ';
    }
    cout << "\n\n";

    BubbleSort(array, n);
    cout << "Сортировка пузырьком: ";
    for (int i = 0; i < n; ++i) 
    {
        cout << array[i] << ' ';
    }
    cout << "\n\n";

    InsertionSort(array, n);
    cout << "Сортировка вставками: ";
    for (int i = 0; i < n; ++i) 
    {
        cout << array[i] << ' ';
    }
    cout << "\n\n";

    cout << "Количество операций сравнения: " << compare_counter << endl;
    cout << "количество операций копирования: " << copy_counter << endl;
    return 0;
}
