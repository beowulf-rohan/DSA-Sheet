#include<bits/stdc++.h>
using namespace std;

void heapify(int* arr, int n, int i)
{
    int largest = i;
    int left = 2*i+1, right = 2*i+2;

    if(left < n && arr[left] > arr[largest])
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;
    
    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int* arr, int n)
{
    int temp = (n-1)/2;
    for(int i = temp; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}