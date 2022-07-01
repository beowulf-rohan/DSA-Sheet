#include<iostream>

using namespace std;

#define MAX 1000000

int multiply(int* output, int num, int size)
{
    int carry = 0;
    
    for(int i = 0; i < size; i++)
    {
        int prod = output[i]*num + carry;
        output[i] = prod%10;
        carry = prod/10;
    }
    
    while(carry)
    {
        output[size] = carry%10;
        carry = carry/10;
        size++;
    }
    return size;
}

void factorial(int n)
{
    int output[MAX];
    output[0] = 1;
    int size = 1;
    
    for(int num = 2; num <= n; num++)
    {
        size = multiply(output, num, size);
    }
    
    for(int i = size-1; i >= 0; i--)
    {
        cout << output[i];
    }
    cout << endl;
}