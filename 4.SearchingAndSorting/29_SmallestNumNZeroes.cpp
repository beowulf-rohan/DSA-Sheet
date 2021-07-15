#include<iostream>
using namespace std;

bool check(int num, int zeroCount)
{
    int multiple = 5;
    int count = 0;
    while(num >= multiple)
    {
        count += num/multiple;
        multiple *= 5;
    }        
    return (count>=zeroCount);
}

int findNum(int n)
{
    if(n == 1)
        return 5;
            
    int low = 0, high = 5*n;
    int ans = -1;
            
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(check(mid, n))
        {
            ans = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return ans;
}