#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node *move(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *last = head->next;
    Node *secLast = head;

    while (last->next != NULL)
    {
        secLast = last;
        last = last->next;
    }
    secLast->next = NULL;
    last->next = head;
    head = last;
    return head;
}