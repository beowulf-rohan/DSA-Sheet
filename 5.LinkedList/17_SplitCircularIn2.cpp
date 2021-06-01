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


void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *slow = head, *fast = head;
    while(fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if(fast->next->next == head)
        fast = fast->next;
        
    *head1_ref = head;
    *head2_ref = slow->next;
    
    slow->next = head;
    fast->next = *head2_ref;
}