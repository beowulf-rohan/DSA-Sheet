#include<iostream>
#include<algorithm>

using namespace std;

struct Time
{
    int s, e, index;
};

bool compare(struct Time a, struct Time b) {
    if (a.e != b.e) {
        return a.e < b.e;
    }
    return a.index < b.index;
}

int activitySelection()
{
    int n;
    cin >> n;

    Time arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].s >> arr[i].e;
        arr[i].index = i+1;
    }

    sort(arr, arr+n, compare);
    
    int ending = arr[0].e;
    int count = 1;
    for (int i = 1; i < n; i++) 
    {
        if (ending <= arr[i].s)         // Can be < instead of <=
        {
            count++;
            ending = arr[i].e;
        }
    }
    return count;
}