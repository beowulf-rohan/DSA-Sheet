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

Node* addOne(Node *head) 
{
   head = reverse(head);
   Node* curr = head, *prev = NULL;
   int carry = 1;
   while(curr)
   {
        int sum = curr->data + carry;
        curr->data = sum%10;
        carry = sum/10;
        prev = curr;
        curr = curr->next;
   }
   if(carry)
        prev->next = new Node(carry);
    return reverse(head);
}
