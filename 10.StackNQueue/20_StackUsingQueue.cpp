#include<bits/stdc++.h>
using namespace std;

class QueueStack
{
    private:
        queue<int> q1;
        queue<int> q2;
    public:
        void push(int);
        int pop();
};

void QueueStack :: push(int x)
{
    
    q2.push(x);
    
    while(q1.size() != 0)
    {
        q2.push(q1.front());
        q1.pop();
    }  
    swap(q1, q2);
}

int QueueStack :: pop()
{
        if(q1.size() == 0 && q2.size() == 0)
        {
            return -1;
        }
        
        int toDel = q1.front();
        q1.pop();
        return toDel;
}