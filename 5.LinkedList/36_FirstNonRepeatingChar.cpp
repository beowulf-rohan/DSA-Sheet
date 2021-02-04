#include<iostream>

using namespace std;

class Node
{
public:
    char data;
    Node *next;

public:
    Node(char data)
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
        char num;
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

void deleteLL(Node *head)
{
    if (head == NULL)
        return;

    deleteLL(head->next);
    delete head;
}

#include <queue>

void nonRep(Node *head)
{
    Node *temp = head;

    queue<char> q;
    int charC[256] = {0};

    while (temp != NULL)
    {
        char c = temp->data;

        q.push(c);
        charC[c]++;

        while (!q.empty())
        {
            if (charC[q.front()] > 1)
                q.pop();
            else
            {
                cout << q.front() << " ";
                break;
            }
        }
        if (q.empty())
            cout << -1 << " ";

        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = input();

        nonRep(head);

        deleteLL(head);
    }
    return 0;
}