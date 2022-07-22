#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Given a singly linked list:  A0→A1→…→An-1→An, 
// reorder it to:               A0→An→A1→An-1→A2→An-2→…
    
Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *after = NULL;
    while (curr != NULL)
    {
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }
    return prev;
}

Node* getMid(Node* head)
{
    Node* prevMid = NULL;
    while(head && head->next)
    {
        prevMid = (prevMid == NULL) ? head : prevMid->next;
        head = head->next->next;
    }
    
    Node* mid = prevMid->next;
    prevMid->next = NULL;
    return mid;
}

void reorderList(Node* head) 
{
    if(!head || !head->next)
        return;
    Node* head1 = head;
    Node* head2 = getMid(head);
    head2 = reverse(head2);
    
    head = new Node(0);
    Node* curr = head;
    while(head1 || head2)
    {
        if(head1)
        {
            curr->next = head1;
            curr = head1;
            head1 = head1->next;
        }
        if(head2)
        {
            curr->next = head2;
            curr = head2;
            head2 = head2->next;
        }
    }
    head = head->next;
}