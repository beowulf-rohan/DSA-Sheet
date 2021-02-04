#include<iostream>

using namespace std;

int findMajority(int* arr, int size)
{
    int element = 0, count = 0;
    for(int i = 0; i < size; i++)
    {
        if(count == 0)
        {
            element = arr[i];
        }
        
        if(element == arr[i])
            count++;
        else
            count--;
    }
    return element;
}

int majorityElement(int arr[], int size)
{
    int maxElement = findMajority(arr, size);
    int count = 0;
    
    for(int i = 0; i < size; i++)
    {
        if(maxElement == arr[i])
            count++;
    }
    
    if(count > size/2)
        return maxElement;
    
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

        cout << majorityElement(arr, n) << endl;
    }
}