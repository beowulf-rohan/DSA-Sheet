#include<bits/stdc++.h>
using namespace std;

struct Meet
{
    int s, e, pos;
};

bool compare(struct Meet ob1, struct Meet ob2)
{
    return ob1.e < ob2.e;
}

vector<int> maxMeeting(int* arr, int* dep, int n)
{
    Meet meeting[n];
    for(int i = 0; i < n; i++)
    {
        meeting[i].s = arr[i];
        meeting[i].e = dep[i];
        meeting[i].pos = i+1;
    }

    sort(meeting, meeting+n, compare);
    
    vector<int> v;
    int ending = meeting[0].e;
    for(int i = 1; i < n; i++)
    {
        if(meeting[i].s >= ending)
        {
            ending = meeting[i].s;
            v.push_back(meeting[i].pos);
        }
    }

    return v;
}