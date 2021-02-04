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

struct Node *start = NULL;

struct Node *segregate(struct Node *head);

void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void insert(int n1)
{
    int n, value, i;
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);

        if (i == 0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main()
{

    int n;

    int t;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);

        insert(n);
        struct Node *newHead = segregate(start);
        printList(newHead);
    }

    return 0;
}

Node *segregate(Node *head)
{
    Node *zeroD = new Node(-1);
    Node *oneD = new Node(-1);
    Node *twoD = new Node(-1);

    Node *zero = zeroD, *one = oneD, *two = twoD;
    Node *curr = head;

    while (curr)
    {
        if (curr->data == 0)
        {
            zero->next = curr;
            zero = zero->next;
        }
        else if (curr->data == 1)
        {
            one->next = curr;
            one = one->next;
        }
        else if (curr->data == 2)
        {
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }

    if (oneD->next)
    {
        zero->next = oneD->next;
        one->next = twoD->next;
    }
    else
    {
        zero->next = twoD->next;
    }
    two->next = NULL;
    head = zeroD->next;

    delete zeroD;
    delete oneD;
    delete twoD;

    return head;
}
