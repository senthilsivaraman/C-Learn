#include<iostream>
using namespace std;

int main(){
    int n, i;
    bool isPrime = true;
    cout << "Enter the number to find Prime or not : ";
    cin >> n;

    if(n>0)
    {
        if( n == 1)
        {
            cout << "1 is neither prime nor composite";
        }
        if(n > 1)
        {
             for(int i = 2; i <= n/2; i++)
                {
                    if(n % i == 0)
                    {
                        isPrime = false;
                        break;
                    }
                }

                if(isPrime)
                    cout << n << " is a Prime number";
                else
                    cout << n << " is  not a Prime number";
        }
    }

    else
        cout << "Enter the correct number";
    return 0;

}
