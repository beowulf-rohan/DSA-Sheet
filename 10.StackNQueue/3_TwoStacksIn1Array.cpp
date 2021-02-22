#include<iostream>
using namespace std;


class twoStacks
{
    public  :   int *arr;
                int size;
                int top1, top2;
    public: twoStacks(int n=100)
    {
        size = n; arr = new int[n]; top1 = -1; top2 = size;
    }
 
    void push1(int x);
    void push2(int x);
    int pop1();
    int pop2();
};


void twoStacks :: push1(int x)      /* The method push to push element into the stack 2 */
{
    if(top1 == top2)
        return;
    
    arr[top1++] = x;
}

void twoStacks ::push2(int x)       /* The method push to push element into the stack 2*/
{
    if(top1 == top2)
        return;
    
    arr[top2--] = x;
}
   
int twoStacks ::pop1()              /* The method pop to pop element from the stack 1 */
{
    if(top1 == -1)
        return -1;
    
    int x = arr[--top1];
    return x;
}

int twoStacks :: pop2()             /* The method pop to pop element from the stack 2 */
{
    if(top2 == size)
        return -1;
    
    int x = arr[++top2];
    return x;
}