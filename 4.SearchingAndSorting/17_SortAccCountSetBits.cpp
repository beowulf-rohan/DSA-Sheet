#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

typedef long long int ll;

bool compare(int a, int b)
{
    int setA = __builtin_popcount(a);
    int setB = __builtin_popcount(b);
    if(setA > setB)
        return true;
    else
        return false;
}

void sortSetBits(int* arr, int n)
{
    stable_sort(arr, arr+n, compare);
}


int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
       
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin >> arr[i];
        
        sortSetBits(arr,n);

        for(int i=0;i<n;i++)
            cout << arr[i] << " ";
    }
	return 0;
}