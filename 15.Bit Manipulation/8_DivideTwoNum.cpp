#include<iostream>
#include<cmath>
#include<climits>

using namespace std;

typedef long long int ll;

ll divide(ll dividend, ll divisor)
{
    int sign = ((dividend<0)^(divisor<0)) ? -1:1;
    
    dividend = abs(dividend);
    divisor = abs(divisor);
    
 
    ll ans = 0, temp = 0;
    for(int i = 31; i >= 0; i--)
    {
        if(temp + (divisor<<i) <= dividend)
        {
            temp += (divisor<<i);
            ans |= (1LL<<i);
        }
    }
    
    ans *= sign;
    return (ans >= INT32_MAX || ans <= INT32_MIN) ? INT32_MAX:ans;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << divide(a, b);
    return 0;
}