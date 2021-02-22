#include<bits/stdc++.h>
using namespace std;


// TC - O(n).... SC - O(1)....
int minElement;
void push(stack<int>& s, int a)
{
	if(s.size() == 0)
	{
	    s.push(a);
	    minElement = a;
	    return;
	}
	
	if(a >= minElement)
	{
	    s.push(a);
	}
	else
	{
	    minElement = a;
	    s.push(2*a - minElement);
	}
}

int pop(stack<int>& s)
{
	if(s.size() == 0)
	    return -1;
	
	if(s.top() >= minElement)
	{
	    int x = s.top();
	    s.pop();
	    return x;
	}
	else
	{
	    int x = minElement;
	    minElement = 2*minElement - s.top();
	    s.pop();
	    return x;
	}
}

int getTop(stack<int>& s)
{
    if(s.top() >= minElement)
        return s.top();
    else
        return minElement;
}

int getMin(stack<int>& s)
{
	if(s.size() == 0)
	    return -1;
	return minElement;
}


// TC - O(n).... SC - O(n)....
stack<int> minStack;
void push(stack<int>& s, int a)
{
	s.push(a);
	if(minStack.size() == 0 || a <= minStack.top())
	    minStack.push(a);
}

int pop(stack<int>& s)
{
    if(s.size() == 0)
        return -1;
    if(s.top() == minStack.top())
        minStack.pop();
    int x = s.top();
	s.pop();
	return x;
}

int getTop(stack<int>& s)
{
    return s.top();
}

int getMin(stack<int>& s)
{
    if(minStack.size() == 0)
        return -1;
	return minStack.top();
}