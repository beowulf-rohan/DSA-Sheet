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

Node *input()
{
    int n;
    cin >> n;
    Node *head = NULL;
    Node *tail = NULL;
    while (n--)
    {
        int num;
        cin >> num;
        Node *newNode = new Node(num);
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
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteLL(Node *head)
{
    if (head == NULL)
        return;

    deleteLL(head->next);
    delete head;
}

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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = input();

        head = segregate(head);
        print(head);

        deleteLL(head);
    }
    return 0;
}