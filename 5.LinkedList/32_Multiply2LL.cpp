#include<iostream>

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

struct Node *newNode(int data)
{
    struct Node *new_Node = new Node(data);

    return new_Node;
}

Node *reverse(Node **r)
{
    Node *prev = NULL;
    Node *cur = *r;
    Node *nxt;
    while (cur != NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *r = prev;
}

void push(struct Node **head_ref, int new_data)
{
    struct Node *new_Node = newNode(new_data);
    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}

void freeList(struct Node *Node)
{
    struct Node *temp;
    while (Node != NULL)
    {

        temp = Node;
        Node = Node->next;
        free(temp);
    }
}

long long multiplyTwoLists(struct Node *, struct Node *);

void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

int main(void)
{

    int t, n, m, i, x;
    cin >> t;
    while (t--)
    {

        struct Node *first = NULL;
        struct Node *second = NULL;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> x;
            push(&first, x);
        }
        cin >> m;
        for (i = 0; i < m; i++)
        {
            cin >> x;
            push(&second, x);
        }

        reverse(&first);
        reverse(&second);
        long long res = multiplyTwoLists(first, second);

        cout << res << endl;
        freeList(first);
        freeList(second);
    }
    return 0;
}

#define mod 1000000007
typedef long long int ll;

long long multiplyTwoLists(Node *l1, Node *l2)
{
    ll num1 = 0, num2 = 0;
    Node *first = l1, *second = l2;
    while (first || second)
    {
        if (first)
        {
            num1 = ((num1 * 10) % mod + (first->data) % mod) % mod;
            first = first->next;
        }
        if (second)
        {
            num2 = ((num2 * 10) % mod + (second->data) % mod) % mod;

            second = second->next;
        }
    }

    return (num1 * num2) % mod;
}