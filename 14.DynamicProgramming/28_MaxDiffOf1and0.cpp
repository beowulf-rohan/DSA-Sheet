#include<bits/stdc++.h>
using namespace std;

int maxSubstring(string s)
{
	int n = s.size();
    int sum = 0;
	int maxSum = INT_MIN;
	for(int i = 0; i < n; i++)
	{
        if(s[i] == '0')
	        sum++;
	    else
	        sum--;
	            
	    maxSum = max(maxSum, sum);
	    if(sum < 0)
	        sum = 0;
	       
	}
	if(abs(maxSum) == 0)
	    return -1;
	return maxSum;
}