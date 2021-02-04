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

Node *reverse(Node *head)
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

bool isPalindrome(Node *head)
{
    Node *slow = head;
    Node *fast = slow;

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *h1 = head;
    Node *h2 = slow;

    if (fast)
        h2 = h2->next;
    h2 = reverse(h2);
    while (h2 != NULL)
    {
        if (h1->data != h2->data)
            return false;
        h1 = h1->next;
        h2 = h2->next;
    }
    return true;
}

int main()
{
    Node *head = input();
    cout << "Linked List : ";
    print(head);

    cout << isPalindrome(head);

    deleteLL(head);
    return 0;
}