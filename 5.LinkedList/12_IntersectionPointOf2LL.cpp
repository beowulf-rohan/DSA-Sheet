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


int findSize(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int intersectPoint(Node *head1, Node *head2)
{
    int size1 = findSize(head1);
    int size2 = findSize(head2);

    Node *temp1, *temp2;

    int d = (size1>size2) ? (size1-size2) : (size2-size1);        //abs(size1 - size2);
    temp1 = (size1 >= size2) ? head1 : head2;
    temp2 = (size1 < size2) ? head1 : head2;
    while (d--)
    {
        temp1 = temp1->next;
    }

    while (temp1 && temp2)
    {
        if (temp1 == temp2)
            return temp1->data;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return -1;
}
