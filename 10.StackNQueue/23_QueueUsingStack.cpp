#include<bits/stdc++.h>
using namespace std;

class StackQueue
{
    private:   
        stack<int> s1;
        stack<int> s2;

    public:
        void push(int);
        int pop();
};


void StackQueue :: push(int x)
{
    s1.push(x);
}

int StackQueue :: pop()
{
    if(s1.size() == 0 && s2.size() == 0)
        return -1;
    
    if(s2.size() == 0)
    {
        while(s1.size() != 0)
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    
    int toDel = s2.top();
    s2.pop();
    return toDel;
}

int StackQueue :: pop()
{
    if(s1.size() == 0 && s2.size() == 0)
        return -1;
    
    while(s1.size() != 0)
    {
        s2.push(s1.top());
        s1.pop();
    }
    
    int toDel = s2.top();
    s2.pop();
        
    while(s2.size() != 0)
    {
        s1.push(s2.top());
        s2.pop();
    }
        
    return toDel;
}