#include <iostream>
using namespace std;

long long int merge(int* arr, int l, int m, int r)
{
	int temp[r-l+1];
	long long int i = l, j = m, count = 0, k = 0;
	while(i < m && j <= r)
	{
		if(arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
		{
			temp[k++] = arr[j++];
			count += (m-i);
		}
	}
	while(i < m)
	{
		temp[k++] = arr[i++];
	}
	while(j <= r)
	{
		temp[k++] = arr[j++];
	}
	
	for(int i = l, k = 0; i <= r; i++, k++)
	{
		arr[i] = temp[k];
	}
	return count;
}

long long int mergeSort(int* arr, int l, int r)
{
	long long int count = 0;
	if(r > l)
	{
		int mid = (l+r)/2;
		long long int leftCount = mergeSort(arr, l, mid);
		long long int rightCount = mergeSort(arr, mid+1, r);
		
		long long int mergeCount = merge(arr, l, mid+1, r);
		
		count = leftCount + rightCount + mergeCount;
	}
	return count;
}
