#include<bits/stdc++.h>
using namespace std;

int kthElement(int arr1[], int arr2[], int m, int n, int k)
    {
        if(k > m+n || k == 0)
            return -1;
        if(m > n)
            return kthElement(arr2, arr1, n, m, k);
        
        if(m == 0)
            return arr2[k-1];
        if(k == 1)
            return min(arr1[0], arr2[0]);
        
        int i = min(m, k/2);
        int j = min(n, k/2);
        
        if(arr1[i-1] > arr2[j-1])
            return kthElement(arr1, arr2+j, m, n-j, k-j);
        else
            return kthElement(arr1+i, arr2, m-i, n, k-i);
    }