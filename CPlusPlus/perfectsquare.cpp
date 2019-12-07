#include<iostream>
using namespace std;

bool isPerfectSquare(int n)
{
    for(int i = 1; i*i <= n; i++)
    {
        if(( n % i == 0) && ( n / i == i))
            return true;
    }
    return false;


     //long double sr = sqrt(x);
     //return ((sr - floor(sr)) == 0);
}
int main()
{
    long int n;
    cout << "Enter the number : ";
    cin >> n;
    if(isPerfectSquare(n))
        cout << n << " is Perfect Square";
    else
        cout << n <<" is not a Perfect Square";
}
