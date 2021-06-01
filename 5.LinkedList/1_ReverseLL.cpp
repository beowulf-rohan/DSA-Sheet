#include <iostream>
using namespace std;

class Node {
    public  :   int data;
                Node *next;

    public  :   Node(int data)
                {
                    this->data = data;
                    next = NULL;
                }
};
       
Node *reverseItr(Node *head)
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

Node *reverseRec(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *nextNode = head->next;
    head->next = NULL;

    Node *rest = reverseRec(nextNode);
    nextNode->next = head;

    return rest;
}