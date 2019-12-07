#include<iostream>
using namespace std;

int main()
{
    int a = 0, b = 1, sum = 0;
    int n;
    cout << "Enter the Fibonacci range : ";
    cin >> n;

    if(n == 1)
    {
       cout << "\t" << a << endl;
    }


    if(n == 2)
    {
        cout<< a << "\t" << b << "\t";
    }


     if(n > 2)
     {
         cout << a << "\t" << b << "\t";
        for(int i = 3; i <= n; i++)
        {
            sum = a + b;
            cout << sum << "\t";
            a = b;
            b = sum;
        }
     }



}
