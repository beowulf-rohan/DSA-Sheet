#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node* arb;
    Node(int x)
    {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

Node *copyList(Node *head) 
{
    Node* curr = head;
    while(curr != NULL)
    {
        Node* newNode = new Node(curr->data);
        newNode->next = curr->next;
        curr->next = newNode;
        curr = newNode->next;
    }
    
    curr = head;
    while(curr)
    {
        curr->next->arb = (curr->arb) ? curr->arb->next : curr->arb;
        curr = curr->next->next;
    }
    
    Node* orignal = head;
    Node* copy = head->next;
    Node* toReturn = copy;
    while(orignal && copy)
    {
        orignal->next = orignal->next->next;
        copy->next = (copy->next) ? copy->next->next : copy->next;
        orignal = orignal->next;
        copy = copy->next;
    }
    return toReturn;
}