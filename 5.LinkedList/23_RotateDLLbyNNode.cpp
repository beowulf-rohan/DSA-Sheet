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


Node *rotateDLL(Node *head, int n)
{
    if (n == 0)
        return head;

    int count = 0;
    Node *curr = head;
    while (count < n - 1 && curr != NULL) //Move pointer to prev to Nth Node
    {
        curr = curr->next;
        count++;
    }

    if (curr == NULL) //Nth Node doew not exist
        return head;

    Node *NthNode = curr;

    while (curr->next != NULL)
        curr = curr->next;

    curr->next = head; //Link last and first node
    head->prev = curr;

    head = NthNode->next; //Reallocate head

    NthNode->next = NULL; //Break link of NthNode and
    head->prev = NULL;    //its previous Node

    return head;
}