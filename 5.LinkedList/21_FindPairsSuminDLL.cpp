#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

void pairSum(Node *head, int sum)
{
    Node *front = head;
    Node *back = head;

    while (back->next != NULL)
        back = back->next;

    while (front != NULL && back != NULL && front != back)
    {
        int tempSum = front->data + back->data;
        if (tempSum == sum)
        {
            cout << "(" << front->data << "," << back->data << ") ";
            front = front->next;
            back = back->prev;
        }
        else if (tempSum > sum)
        {
            back = back->prev;
        }
        else if (tempSum < sum)
        {
            front = front->next;
        }
    }
}
