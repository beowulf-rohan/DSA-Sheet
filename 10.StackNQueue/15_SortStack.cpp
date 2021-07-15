#include<bits/stdc++.h>
using namespace std;


// TC - O(n2)... SC - O(n)....
stack<int> sortStack(stack<int> s)
{
    stack<int> rev;
    while(s.size() != 0)
    {
        int temp = s.top();
        s.pop();
        while(rev.size() != 0 && rev.top() > temp)
        {
            s.push(rev.top());
            rev.pop();
        }
        rev.push(temp);
    }
    return rev;
}


// TC - O(n2)... SC - O(n)....
void insert(int temp, stack<int> &s)
{
    if(s.empty() ||  temp > s.top())
    {
        s.push(temp);
        return;
    }
    
    int x = s.top();
    s.pop();
    insert(temp, s);

    s.push(x);
}

void sort(stack<int> &s)
{
    if(s.empty())
        return;
    int temp = s.top();
    s.pop();
    sort(s);
    
    insert(temp, s);
}