#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node *newNode(int data)
{
    Node *temp = new Node(data);

    return temp;
}

void displayList(Node *head)
{
    //Head to Tail
    while (head->next)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data;
    cout << endl;
}

int pairSum(Node *head, int sum)
{
    int count = 0;
    Node *front = head;
    Node *back = head;

    while (back->next != NULL)
        back = back->next;

    while (front != NULL && back != NULL && front != back)
    {
        int tempSum = front->data + back->data;
        if (tempSum == sum)
        {
            count++;
            front = front->next;
            back = back->prev;
        }
        else if (tempSum > sum)
        {
            back = back->prev;
        }
        else if (tempSum < sum)
        {
            front = front->next;
        }

        if (back->next == front)
            break;
    }
    return count;
}

int tripletSum(Node *head, int sum)
{
    Node *front = head;
    if (front == NULL || front->next == NULL)
        return 0;

    int count = 0;

    while (front->next->next)
    {
        count += pairSum(front->next, sum - (front->data));
        front = front->next;
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Node *head = NULL, *tail = NULL;
        int x;
        cin >> x;
        head = newNode(x);
        tail = head;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> x;
            Node *temp = newNode(x);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        cout << "Doubly LL : ";
        displayList(head);

        int sum;
        cin >> sum;
        cout << tripletSum(head, sum) << endl;
    }
    return 0;
}