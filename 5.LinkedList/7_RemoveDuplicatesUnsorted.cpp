#include <bits/stdc++.h>
#include <unordered_set>
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

Node *removeDuplicates(Node *head)
{
    unordered_set<int> mySet;
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        if (mySet.count(curr->data) != 0)
        {
            prev->next = curr->next;
            delete curr;
        }
        else
        {
            prev = curr;
            mySet.insert(curr->data);
        }
        curr = prev->next;
    }
    return head;
}
