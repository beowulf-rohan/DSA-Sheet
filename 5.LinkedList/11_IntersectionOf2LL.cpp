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

Node* findIntersection(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;

    Node *temp1 = head1, *temp2 = head2;
    while (temp1 && temp2)
    {
        if (temp1->data < temp2->data)
            temp1 = temp1->next;
        else if (temp2->data < temp1->data)
            temp2 = temp2->next;
        else
        {
            Node *newNode = new Node(temp1->data);

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
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    return head;
}