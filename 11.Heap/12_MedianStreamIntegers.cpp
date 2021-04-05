#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
        
    public:
    void insertHeap(int &x)
    {
        if(maxHeap.size() == 0)
        {
            maxHeap.push(x);
        }
        else if(maxHeap.size() == minHeap.size())
        {
            if(x < minHeap.top())
                maxHeap.push(x);
            else
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                
                minHeap.push(x);
            }
        }
        else
        {
            if(minHeap.size() == 0)
            {
                if(x > maxHeap.top())
                    minHeap.push(x);
                else
                {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    
                    maxHeap.push(x);
                }
            }
            else if(x > maxHeap.top())
                minHeap.push(x);
            else
            {
                if(x < maxHeap.top())
                {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    
                    maxHeap.push(x);
                }
                else
                    minHeap.push(x);
            }
        }
    }
    
    double getMedian()
    {
        if(minHeap.size() == maxHeap.size())
            return 1.0*(minHeap.top() + maxHeap.top())/2;
        else
            return 1.0*(maxHeap.top());
    }
};