#include<iostream>
using namespace std;

int main()
{
    int a = 10, b = 20;
    cout << "Before Swap" << "\t" << a << "\t" << b << endl;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "After Swap" << "\t" << a << "\t" << b;
}
