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

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        node = node->next;
    }
    cout << "\n";
}

Node *addOne(Node *head);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Node *head = new Node(s[0] - '0');
        Node *tail = head;
        for (int i = 1; i < s.size(); i++)
        {
            tail->next = new Node(s[i] - '0');
            tail = tail->next;
        }

        head = addOne(head);
        printList(head);
    }
    return 0;
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

Node *addOne(Node *head)
{
    head = reverse(head);

    int carry = 1;
    Node *curr = head;

    while (carry)
    {
        curr->data += carry;
        if (curr->data < 10)
            return reverse(head);
        else
            curr->data = 0;

        if (curr->next == NULL)
            break;
        else
            curr = curr->next;
    }

    curr->next = new Node(carry);
    return reverse(head);
}

/*
Node* addOne(Node *head) 
{
    head = reverse(head);
    int carry = 1;
    Node* temp = head;
    while(temp != NULL)
    {
        if(carry == 1)
        {
            temp->data += carry;
            carry = (temp->data)/10;
            temp->data %= 10;
        }
        if(temp->next == NULL && carry == 1)
        {
            Node* newNode = new Node(1);
            temp->next = newNode;
            carry = 0;
        }
        temp = temp->next;
    }
    head = reverse(head);
    return head;
}
*/