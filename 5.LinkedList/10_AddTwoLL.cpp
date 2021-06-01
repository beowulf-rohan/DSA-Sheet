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

Node* reverse(Node* head)
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

Node *addTwoLL(Node *first,  Node *second)
{
    first = reverse(first);
    second = reverse(second);

    Node *head = NULL;
    Node *tail = NULL;
    int carry = 0, sum = 0;
    while (first != NULL || second != NULL)
    {
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        carry = sum / 10;
        sum %= 10;

        Node *newNode = new Node(sum);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }

        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
    if (carry)
    {
        tail->next = new Node(carry);
        tail = tail->next;
    }

    return reverse(head);
}
