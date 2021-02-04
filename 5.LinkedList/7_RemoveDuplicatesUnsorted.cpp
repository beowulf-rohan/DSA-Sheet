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
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

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

#include <unordered_set>
Node *removeDuplicates(Node *head)
{
    unordered_set<int> mySet;
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        if (mySet.count(curr->data) != 0)
        {
            prev->next = curr->next;
            delete curr;
        }
        else
        {
            prev = curr;
            mySet.insert(curr->data);
        }
        curr = prev->next;
    }
    return head;
}
