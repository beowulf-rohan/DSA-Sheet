#include<bits/stdc++.h>
using namespace std;

string smallestNumber(int s, int d)
{
    int* arr = new int[d]();
    arr[0] =  1;
    s--;
    for(int i = d-1; i >= 1; i--)
    {
        if(s >= 9)
        {
            arr[i] = 9;
            s -= 9;
        }
        else
        {
            arr[i] = s;
            s = 0;
        }
    }
    if(s > 8)
        return "-1";
    else if(s > 0)
        arr[0] += s;
        
    string str;
    for(int i = 0; i < d; i++)
    {
        str.push_back(arr[i]+'0');
    }
    return str;
}