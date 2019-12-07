#include <iostream>
using namespace std;
int main()
{
    int n;
    int sum = 1;
    cout << "Enter the number to find the Factorial : ";
    cin >> n;
    if(n < 0)
    {
        cout << "Enter the number greater or equal to 0";
    }
    else{
        for(int i = 1; i <= n; i++)
        {
            sum = sum * i;
        }
        cout << "The Factorial of " << n << " is : " << sum;
    }
}
