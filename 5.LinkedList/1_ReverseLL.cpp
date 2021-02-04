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

Node *reverseItr(Node *head)
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

Node *reverseRec(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *nextNode = head->next;
    head->next = NULL;

    Node *rest = reverseRec(nextNode);
    nextNode->next = head;

    return rest;
}

int main()
{
    Node *head = input();
    cout << "Linked List : ";
    print(head);

    head = reverseItr(head);
    cout << "1st reversal : ";
    print(head);

    head = reverseRec(head);
    cout << "2nd reversal : ";
    print(head);

    delete head;
    return 0;
}