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

Node *removeDuplicates(Node *root)
{
    Node* head = root;
    Node* curr = root->next;
    
    while(curr != NULL)
    {
        if(head->data == curr->data)
        {
            Node* toDel = curr;
            curr = curr->next;
            toDel->next = NULL;
            delete toDel;
            head->next = curr;
        }
        else
        {
            head = head->next;
            curr = curr->next;
        }
    }
    return root;
}