#include<iostream>
using namespace std;

bool isPowerofTwo(long long n)
{
    return !(n&(n-1));    
}

int main()
{
    long long int n;
    cin >> n;

    cout << isPowerofTwo(n);

    return 0;
}