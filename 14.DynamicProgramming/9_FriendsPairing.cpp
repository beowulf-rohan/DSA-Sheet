#include<bits/stdc++.h>
using namespace std;

long long int p = 1e9+7;

int countFriendsPairings(int n) 
{ 
    if(n == 1 || n == 2)
        return n;
    long long int a = 1, b = 2, c;
    for(int i = 3; i <= n; i++)
    {
        c = (b%p + ((i-1)%p*a%p)%p)%p;
        a = b;
        b = c;
    }
    return c;
}