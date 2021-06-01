// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};


int startingPoint(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    bool found = false;
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            found = true;
            break;
        }
    }

    if(found)
    {
        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow->data;
    }
    return -1;

}
