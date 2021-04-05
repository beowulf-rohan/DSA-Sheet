#include<iostream>
using namespace std;

void heapifyMax(int* arr, int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && arr[l] > arr[largest])
        largest = l;
    if(r < n && arr[r] > arr[largest])
        largest = r;
    
    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void maxHeapify(int* arr, int n)
{
    for(int i = (n-2)/2; i >= 0; i--)
    {
        heapifyMax(arr, n, i);
    }
}


void heapifyMin(int* arr, int n, int i)
{
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && arr[l] < arr[smallest])
        smallest = l;
    if(r < n && arr[r] < arr[smallest])
        smallest = r;
    
    if(smallest != i)
    {
        swap(arr[smallest], arr[i]);
        heapifyMin(arr, n, smallest);
    }
}

void minHeapify(int* arr, int n)
{
    for(int i = (n-2)/2; i >= 0; i--)
    {
        heapifyMin(arr, n, i);
    }
}


int main()
{
    int n;
    cin >> n;
    
    cout << "\nMax to Min :: " << endl;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    maxHeapify(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }cout << endl;


    cout << "\nMin to Max :: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    minHeapify(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }cout << endl;
    return 0;
}