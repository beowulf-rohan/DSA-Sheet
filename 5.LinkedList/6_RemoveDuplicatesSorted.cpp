#include <bits/stdc++.h>
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

Node * uniqueSortedList(Node * head) 
{
    Node* temp = new Node(-1);
    temp->next = head;
    Node* curr = head;
    Node* prev = temp;
    while(curr)
    {
        while(curr && (prev->data == curr->data))
            curr = curr->next;
        prev->next = curr;
        prev = curr;
    }
    return temp->next;
}