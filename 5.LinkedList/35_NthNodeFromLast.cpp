#include<bits/stdc++.h>
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

int getNthFromLast(Node *head, int n)
{
    Node *currNode = head, *nthNode = head;

    while (n != 0)
    {
        if (currNode == NULL)
            return -1;
        currNode = currNode->next;
        n--;
    }

    while (currNode != NULL)
    {
        nthNode = nthNode->next;
        currNode = currNode->next;
    }

    if (nthNode != NULL)
        return nthNode->data;
    else
        return -1;
}