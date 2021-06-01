// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/* Link list Node */
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

bool isCircular(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        if (temp == head)
            return true;
    }
    return false;
}