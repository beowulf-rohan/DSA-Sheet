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

Node *middleNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    Node *head = input();
    cout << "Linked List : ";
    print(head);

    Node* temp = middleNode(head);
    cout << "From Middle of Linked List : ";
    print(temp);

    deleteLL(head);
    delete(temp);
    
    return 0;
}