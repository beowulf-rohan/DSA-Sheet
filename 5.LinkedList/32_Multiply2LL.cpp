#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

#define mod 1000000007
typedef long long int ll;

long long multiplyTwoLists(Node *l1, Node *l2)
{
    ll num1 = 0, num2 = 0;
    Node *first = l1, *second = l2;
    while (first || second)
    {
        if (first)
        {
            num1 = ((num1 * 10) % mod + (first->data) % mod) % mod;
            first = first->next;
        }
        if (second)
        {
            num2 = ((num2 * 10) % mod + (second->data) % mod) % mod;

            second = second->next;
        }
    }

    return (num1 * num2) % mod;
}