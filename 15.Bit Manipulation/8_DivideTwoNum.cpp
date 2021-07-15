#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int divide(int A, int B)
{
    int sign = ((A < 0) ^ (B < 0)) ? -1 : 1;
    long long int dividend = A, divisor = B;
    long long int quotient = 0, sum = 0;

    dividend = abs(dividend);       divisor = abs(divisor);

    for(int i = 31; i >= 0; i--)
    {
        if(sum + (divisor << i) <= dividend)
        {
            sum += (divisor << i);
            quotient |= (1LL<<i);
        }
    }

    if(sign < 0)
        quotient = -quotient;
    
    return (quotient >= INT_MAX || quotient < INT_MIN) ? INT_MAX : quotient;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << divide(a, b);
    return 0;
}