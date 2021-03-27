#include<bits/stdc++.h>
using namespace std;

void reverse(queue<int> &q)
{
    if(q.size() == 0)
        return;
    
    int front = q.front();
    q.pop();
    reverse(q);
    q.push(front);
}

queue<int> rev(queue<int> q)
{
    reverse(q);
    return q;
}