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

Node *move(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *last = head->next;
    Node *secLast = head;

    while (last->next != NULL)
    {
        secLast = last;
        last = last->next;
    }
    secLast->next = NULL;
    last->next = head;
    head = last;
    return head;
}

int main()
{
    Node *head = input();
    cout << "Linked List : ";
    print(head);

    head = move(head);
    cout << "New Linked List : ";
    print(head);

    deleteLL(head);
    return 0;
}