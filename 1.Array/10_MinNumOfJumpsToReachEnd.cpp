#include<iostream>

using namespace std;

//O(n2) TC and O(n) SC
/*
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
*/

//O(n) TC and O(1) SC`

int minJumps(int* arr, int n)
{  
    // The number of jumps needed to reach the starting index is 0 
    if (n <= 1) 
        return 0; 
  
    // Return -1 if not possible to jump 
    if (arr[0] == 0) 
        return -1; 
  
    // initialization 
    int maxReach = arr[0];
    int step = arr[0];
    int jump =1;
  
    // Start traversing array 
    int i=1; 
    for (i = 1; i < n; i++) 
    { 
        // Check if we have reached the end of the array 
        if (i == n-1) 
            return jump; 
  
        // updating maxReach 
        maxReach = max(maxReach, i+arr[i]); 
  
        // we use a step to get to the current index 
        step--; 
  
        // If no further steps left 
        if (step == 0) 
        { 
            // we must have used a jump 
            jump++; 
  
            // Check if the current index/position or lesser index 
            // is the maximum reach point from the previous indexes 
            if(i >= maxReach) 
                return -1; 
  
            // re-initialize the steps to the amount 
            // of steps to reach maxReach from position i. 
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