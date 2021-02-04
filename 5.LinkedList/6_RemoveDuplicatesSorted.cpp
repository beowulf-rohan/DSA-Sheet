#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *removeDuplicates(Node *root);
int main()
{
    // your code goes here
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < K; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Node *result = removeDuplicates(head);
        print(result);
        cout << endl;
    }
    return 0;
}

Node *removeDuplicates(Node *root)
{
    if (root == NULL)
        return root;

    Node *head = root;
    Node *curr = root->next;

    while (curr != NULL)
    {
        if (curr->data == head->data)
        {
            Node *toDelete = curr;
            curr = curr->next;
            head->next = NULL;
            delete toDelete;
        }
        else
        {
            head->next = curr;
            head = head->next;
            curr = curr->next;
        }
    }

    return root;
}