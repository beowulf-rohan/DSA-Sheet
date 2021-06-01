#include<iostream>
#include <queue>
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