#include <iostream>
#include <algorithm>
using namespace std;

template<typename TypeOfElement>
class MyVector 
{
public:
    MyVector() : length(0), capacity(1), dataPointer(new TypeOfElement[capacity]) {}

    MyVector(const MyVector& rhs) : length(rhs.Length()), capacity(rhs.Capacity()) 
    {
        this->capacity = rhs.Capacity();
        this->dataPointer = new TypeOfElement[capacity];
        copy_n(rhs.dataPointer, length, dataPointer);
    }

    MyVector& operator=(const MyVector& rhs) 
    {
        length = rhs.Length();
        capacity = rhs.Capacity();
        dataPointer = new TypeOfElement[capacity];
        copy_n(rhs.dataPointer, length, dataPointer);
        return *this;
    };

    [[nodiscard]] const int& At(int index) const 
    {
        return dataPointer[index];
    }

    ~MyVector() 
    {
        delete[] dataPointer;
    }

    void PushBack(TypeOfElement newElement) 
    {
        UpCapacity(capacity + 1);
        dataPointer[length++] = newElement;
    }

    TypeOfElement& operator[](int index) 
    {
        if (index >= length) {
            UpCapacity(index + 1);
            length = index + 1;
        }
        return dataPointer[index];
    }

    [[nodiscard]] bool isEmpty() const 
    {
        return length == 0;
    }

    [[nodiscard]] int Length() const 
    {
        return length;
    }

    [[nodiscard]] int Capacity() const 
    {
        return capacity;
    }

    static void InputVector(MyVector& inVector, int N) 
    {
        TypeOfElement inp;
        for (int i = 0; i < N; i++) {
            cin >> inp;
            inVector.PushBack(inp);
        }
    }

    static void OutputVector(MyVector& outVector) 
    {
        cout << "OutputMyIntVector: ";
        for (int i = 0; i < outVector.Length(); i++) {
            cout << outVector[i] << " ";
        }
        cout << endl;
    }

    MyVector<TypeOfElement> operator+(MyVector<TypeOfElement>& rhs) 
    {
        MyVector<TypeOfElement> outVector;
        for (int i = 0; i < Length(); i++) {
            outVector.PushBack(dataPointer[i]);
        }
        for (int i = 0; i < rhs.Length(); i++) {
            outVector.PushBack(rhs[i]);
        }
        return outVector;
    };




private:
    void UpCapacity(int newCapacity) 
    {
        auto newDataPointer = new TypeOfElement[newCapacity];
        copy_n(dataPointer, length, newDataPointer);
        dataPointer = newDataPointer;
        capacity = newCapacity;
    }

    int length;
    int capacity;
    TypeOfElement* dataPointer;
};

template<class MyType>

void MySwap(MyType& element1, MyType& element2) 
{
    MyType temp = element1;
    element1 = element2;
    element2 = temp;
}

template<typename T>
void my_swap(T& a, T& b) 
{
    T temp = a;
    a = b;
    b = temp;
}


int main() 
{
    setlocale(LC_ALL, "Russian");
    MyVector<int> vec;
    int n;
    cin >> n;
    MyVector<char> v1, v2, v3;
    MyVector<char>::InputVector(v1, n);
    MyVector<char>::InputVector(v2, n);
    v3 = v1 + v2;
    MyVector<char>::OutputVector(v3);

    return 0;
}
