#include <iostream>

using namespace std;

void printArray(int myArray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << myArray[i] << ' ';
    }
    cout << endl;
}

void reverseArray(int myArray[], int size)
{
    int temp[size];
    for (int i = size - 1; i > -1; i--)
    {
        // cout << i << endl;
        // cout << size - i - 1 << endl;
        temp[size - i - 1] = myArray[i];
    }
    printArray(temp, size);
}

int main()
{
    int sizeOfArray;
    cout << "Enter the size of the array: ";
    cin >> sizeOfArray;
    int myArray[sizeOfArray];

    for (int i = 0; i < sizeOfArray; i++)
    {
        cout << "Enter the " << i + 1 << " number: ";
        cin >> myArray[i];
    }
    printArray(myArray, sizeOfArray);
    // reverseArray(myArray, sizeOfArray);

    /**
    Write c++ program to reverse a array:
    Input:
    size: 7
    all the elements: 1 2 3 4 5 6 7

    Output:
    7 6 5 4 3 2 1
    **/
}
