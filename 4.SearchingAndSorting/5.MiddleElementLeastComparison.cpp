#include<iostream>

using namespace std;

int middle(int A, int B, int C)
{
    if (A < B)
        return (B < C)? B : max(A, C);
    return (A < C)? A : max(B, C);
}