#include<iostream>
using namespace std;

void heapify(int* arr, int n, int i)
{
    if(i >= n)
        return;
    int largest = i;
    int left = 2*i + 1, right = 2*i + 2;
    
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
    for(int i = (n-1)/2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void merge(int* a, int* b, int n, int m)
{
    int merged[n+m];
    for (int i = 0; i < n; i++)
        merged[i] = a[i];
    for (int i = 0; i < m; i++)
        merged[n + i] = b[i];
    
    buildHeap(merged, n+m);
    
    for(int i = 0; i < n+m; i++)
    {
        cout << merged[i] << " ";
    }cout << endl;
}