#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll GERGOIVA(int* a, int n)
{
	ll sum = 0;
    for(int i = 0, j = 0; i < n && j < n;)
    {
        if(a[i] <= 0)
        {
       		i++;
          	continue;
        }
        if(a[j] >= 0)
        {
           	j++;
           	continue;
        }
            
        int diff = min(a[i], abs(a[j]));
        sum += diff*abs(i-j);
        a[i] -= diff;
        a[j] += diff;
    }
    return sum;
}
