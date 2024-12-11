#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

typedef int(*CompareFunctionType)(void*, void*);

int Compare(void* first_pointer, void* second_pointer) 
{
	int* first_element_int_pointer = (int*)first_pointer;
	int* second_element_int_pointer = (int*)second_pointer;
	return *first_element_int_pointer - *second_element_int_pointer;
}

int (*compare_function_pointer) (void*, void*) = &Compare;


void InputArray(int input_data[], int length)
{
	cout << "Введите элементы массива целых чисел:" << endl;
	for (int i = 0; i < length; i++)
	{
		int elem;
		cin >> elem;
		input_data[i] = elem;
	}
}

void InputArray(char input_data[], int length) 
{
	cout << "Введите элементы массива символов:" << endl;
	cin.ignore();
	cin.getline(input_data, length);
}

int FindMinIndex(void* data_array, int width, 
	CompareFunctionType compare_function_pointer, 
	int first_index, int last_index) 
{
	int min_index = first_index;
	for (int i = first_index + 1; i < last_index + 1; i++) {
		if (compare_function_pointer(static_cast<char*>(data_array) + i * width, 
			static_cast<char*>(data_array) + min_index * width) < 0) 
		{
			min_index = i;
		}
	}
	return min_index;
}

void SwapChar(char* first_pointer, char* second_pointer) 
{
	char temp = *first_pointer;
	*first_pointer = *second_pointer;
	*second_pointer = temp;
}

void Swap(void* first_pointer, void* second_pointer, int width) 
{
	for (int i = 0; i < width; i++) 
	{
		SwapChar(static_cast<char*>(first_pointer) + i, 
			static_cast<char*>(second_pointer) + i);
	}
}

void SelectionSort(void* data_array, int length, int width, 
	CompareFunctionType compare_function_pointer) 
{
	for (int i = 0; i < length - 1; i++) {
		int min_index = FindMinIndex(data_array, width, compare_function_pointer, i, length - 1);
		if ((*compare_function_pointer)(&min_index, &i) != 0) 
		{
			Swap(static_cast<char*>(data_array) + i * width, static_cast<char*>(data_array) 
				+ min_index * width, width);
		}
	}
}

void OutputArray(int input_data[], int length)
{
	cout << "Отсортированный массив целых чисел: " << endl;
	for (int i = 0; i < length; i++)
		cout << input_data[i] << ' ';
	cout << endl;
}

void OutputArray(char input_data[]) 
{
	cout << "Отсортированный массив символов: " << endl;
	cout << input_data << endl;
}

int CompareInt0to9(void* first_pointer, void* second_pointer)
{
	int* first_int = (int*)(first_pointer);
	int* second_int = (int*)(second_pointer);
	return (*first_int - *second_int);
}

int CompareInt9to0(void* first_pointer, void* second_pointer)
{
	int* first_int = (int*)(first_pointer);
	int* second_int = (int*)(second_pointer);
	return (*second_int - *first_int);
}

int CompareCharAToZ(void* first_pointer, void* second_pointer) 
{
	char* first_char = (char*)(first_pointer);
	char* second_char = (char*)(second_pointer);
	return (*first_char - *second_char);
}

int CompareCharZToA(void* first_pointer, void* second_pointer) 
{
	char* first_char = (char*)(first_pointer);
	char* second_char = (char*)(second_pointer);
	return (*second_char - *first_char);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	const int kLength = 10;
	int my_int_array[kLength];
	char my_char_array[100];
	const int kNumberOfCompareFunctions = 2;
	CompareFunctionType compare_function_pointers_int[kNumberOfCompareFunctions];
	CompareFunctionType compare_function_pointers_char[kNumberOfCompareFunctions];
	compare_function_pointers_int[0] = CompareInt0to9;
	compare_function_pointers_int[1] = CompareInt9to0;
	compare_function_pointers_char[0] = CompareCharAToZ;
	compare_function_pointers_char[1] = CompareCharZToA;
	InputArray(my_int_array, kLength);
	SelectionSort((void*)my_int_array, kLength, 4, compare_function_pointers_int[0]);
	OutputArray(my_int_array, kLength);
	InputArray(my_char_array, 100);
	int actual_length = strlen(my_char_array);
	SelectionSort((void*)my_char_array, actual_length, sizeof(char), 
		compare_function_pointers_char[0]);
	OutputArray(my_char_array);
	return 0;
}
