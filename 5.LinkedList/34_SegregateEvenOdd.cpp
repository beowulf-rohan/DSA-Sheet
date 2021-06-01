#include<iostream>

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


Node *segregate(Node *head)
{
    Node *temp = head;
    Node *eh = NULL, *et = NULL, *oh = NULL, *ot = NULL;

    while (temp != NULL)
    {
        if ((temp->data) % 2 == 0) //Even
        {
            if (eh == NULL)
            {
                eh = temp;
                et = temp;
            }
            else
            {
                et->next = temp;
                et = et->next;
            }
            temp = temp->next;
            et->next = NULL;
        }
        else if ((temp->data) % 2 != 0) //Odd
        {
            if (oh == NULL)
            {
                oh = temp;
                ot = temp;
            }
            else
            {
                ot->next = temp;
                ot = ot->next;
            }
            temp = temp->next;
            ot->next = NULL;
        }
    }

    if (eh == NULL)
        return oh;
    if (oh == NULL)
        return eh;

    et->next = oh;
    return eh;
}