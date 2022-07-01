#include<iostream>

using namespace std;

void rearrange(int* arr, int n)
{
    int pivot = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] >= 0)
        {
            swap(arr[i], arr[pivot]);
            pivot++;
        }
    }
    
    int posIndex = 0, negIndex = pivot;

    while(posIndex < negIndex && posIndex < n && negIndex < n)
    {
        swap(arr[negIndex], arr[posIndex]);
        negIndex+=1;    posIndex+=2;
    }
}