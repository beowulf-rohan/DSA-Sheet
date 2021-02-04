#include<iostream>
#include<vector>

using namespace std;

typedef long long int ll;

vector<ll> prodPuzzle(vector<ll> arr, int n)
{
    vector<ll> prod(n, 1);
    
    ll temp = 1;
    for(int i = 1; i < n; i++)
    {
       temp = temp*arr[i-1];
       prod[i] = prod[i]*temp;
    }
    
    temp = 1;
    for(int i = n-2; i >= 0; i--)
    {
        temp = temp*arr[i+1];
        prod[i] = prod[i]*temp;
    }
    return prod;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        vector<ll> arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<ll> prod =  prodPuzzle(arr, n);
        for(int i = 0; i < n; i++)
        {
            cout << prod[i] << " ";
        }
    }
	return 0;
}