#include<iostream>

using namespace std;

// TC - O(n2).... SC - O(n)

int minJumps(int arr[], int n)
{
    if(n < 1)
        return 0;
    if(arr[0] == 0)
        return -1;
    
    int steps[n], jumps[n];
    for(int i = 0; i < n; i++)
    {
        jumps[i] = INT32_MAX;
    }
    jumps[0] = 0;
    steps[0] = -1;
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(j+arr[j] >= i)
            {
                if(jumps[i] > jumps[j]+1)
                {
                    steps[i] = j;
                    jumps[i] = jumps[j]+1;
                }
            }
        }
    }
    return jumps[n-1];
}

// TC - O(n).... SC - O(n)

int minJumps(int* arr, int n)
{  
    if (n <= 1) 
        return 0; 
  
    if (arr[0] == 0) 
        return -1; 
  
    int maxReach = arr[0], step = arr[0], jump =1;
  
    int i=1; 
    for (i = 1; i < n; i++) 
    { 
        if (i == n-1) 
            return jump; 
        maxReach = max(maxReach, i+arr[i]); 
        step--; 
  
        if (step == 0) 
        { 
            jump++; 
            if(i >= maxReach) 
                return -1; 
            step = maxReach - i; 
        } 
    }
    return -1; 
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << minJumps(arr, n) << endl;
    }
}