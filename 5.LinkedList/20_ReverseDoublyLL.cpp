//Initial Template for C++

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

Node* reverse(Node* head) 
{
    Node* tail = head;
    while(tail->next != NULL)
        tail = tail->next;
    
    Node* curr = head;
    while(curr != NULL)
    {
        Node* nextNode = curr->next;
        curr->next = curr->prev;
        curr->prev = nextNode;
        curr = nextNode;
    }
    
    return tail;
}
