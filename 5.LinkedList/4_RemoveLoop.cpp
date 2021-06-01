// driver code

#include <iostream>
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


void removeLoop(Node *head)
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

    slow = head;
    if (found)
    {
        if (slow == fast)
        {
            while (fast->next != slow)
            {
                fast = fast->next;
            }
        }
        else
        {
            while (slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = NULL;
    }
}