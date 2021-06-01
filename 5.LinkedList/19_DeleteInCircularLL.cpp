// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *deleteNode(Node *head)
{
    if (head == NULL)
        return head;

    int data;
    cin >> data;

    //Single Element which is to be deleted
    if (head->data == data && head->next == head)
    {
        delete head;
        head = NULL;
        return head;
    }

    Node *curr = head, *toDel = head;

    //FirstNode is to be deleted
    if (head->data == data)
    {
        toDel = head;
        while (curr->next != head)
        {
            curr = curr->next;
        }
        curr->next = head->next;
        delete toDel;
        head = curr->next;
        return head;
    }

    //Node not found on First Position
    while (curr->next != head && curr->next->data != data)
    {
        curr = curr->next;
    }

    if (curr->next->data == data)
    {
        Node *toDel = curr->next;
        curr->next = toDel->next;
        delete toDel;
        return head;
    }

    return head;
}