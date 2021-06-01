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

Node *addOne(Node *head)
{
    head = reverse(head);

    int carry = 1;
    Node *curr = head;

    while (carry)
    {
        curr->data += carry;
        if (curr->data < 10)
            return reverse(head);
        else
            curr->data = 0;

        if (curr->next == NULL)
            break;
        else
            curr = curr->next;
    }

    curr->next = new Node(carry);
    return reverse(head);
}

/*
Node* addOne(Node *head) 
{
    head = reverse(head);
    int carry = 1;
    Node* temp = head;
    while(temp != NULL)
    {
        if(carry == 1)
        {
            temp->data += carry;
            carry = (temp->data)/10;
            temp->data %= 10;
        }
        if(temp->next == NULL && carry == 1)
        {
            Node* newNode = new Node(1);
            temp->next = newNode;
            carry = 0;
        }
        temp = temp->next;
    }
    head = reverse(head);
    return head;
}
*/