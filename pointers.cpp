#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    cout << temp << endl;
    a = b;
    b = temp;
}

unsigned long long int factorial(int num)
{
    if (num == 0)
    {
        return 1;
    }
    else if (num < 0)
    {
        return -1;
    }
    else
    {
        return factorial(num - 1) * num;
    }
}

int main()
{
    int x = 200;
    // int y = 3;
    cout << factorial(x) << endl;
    // cout << y << endl;
}