#include<iostream>
#include<vector>

using namespace std;

void frequencycount(vector<int>& arr,int n)
{ 
    vector<int> temp(n);
    
    for(int i = 0; i < n; i++)
    {
        temp[i] = arr[i]-1;
    }
    
    for(int i = 0; i < n; i++)
    {
        temp[temp[i]%n] += n;
    }
    
    for(int i = 0; i < n; i++)
    {
     arr[i] = temp[i]/n;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        frequencycount(arr, n);

        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}