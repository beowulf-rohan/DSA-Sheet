#include<iostream>
#include<vector>

using namespace std;

void threeWayPartition(vector<int>& array,int a, int b)
{
    int size = array.size();
        
    int m = 0, low = 0, high = size-1;
    while(m <= high)
    {
        if(array[m] < a)
            swap(array[m++], array[low++]);
        else if(array[m] > b)
            swap(array[m], array[high--]);
        else
            m++;
    }
}