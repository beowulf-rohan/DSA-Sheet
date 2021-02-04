#include<iostream>
using namespace std;

int copySetBitsinRange(int &a, int b, int l, int r)
{
    int mask = (1<<(r-l+1)) - 1;
    mask = (mask<<(l-1));
    
    mask = (mask&b);
    
    a = (a|mask);

    return a;
}

int main()
{
    int a, b, l, r;
    cin >> a >> b >> l >> r;

    cout << copySetBitsinRange(a, b, l, r);
}