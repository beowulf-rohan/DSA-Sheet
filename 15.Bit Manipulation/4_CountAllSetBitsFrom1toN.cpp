#include<iostream>
#include<cmath>
#include<climits>

using namespace std;

typedef long long int ll;

int countSetBits(int num)
{   if(num == 0)
        return 0;
    
    int x = log2(num);
    
    int btill2x = x*(1<<(x-1));
    int msb2xton = num - (1<<x) + 1;
    int rest = num - (1<<x);
    return btill2x + msb2xton + countSetBits(rest);
}

int main()
{
    int a, b;
    cin >> a;
    cout << countSetBits(a);
    return 0;
}