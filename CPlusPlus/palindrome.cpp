#include<iostream>
using namespace std;

int main()
{
    int n, n1, last, rev = 0;
    cout << "Enter the number to check :";
    cin >> n;
    n1 = n;

    while(n1 >0)
    {
        last = n1 % 10;
        rev = rev *10 + last;
        n1 = n1 / 10;
    }

    cout << "Reversal is : " << rev << endl;
    if(rev == n)
        cout << "n is a Palindrome";
    else
        cout << "n is not a Palindrome";
}

