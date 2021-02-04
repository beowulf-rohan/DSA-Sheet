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

Node *rotateDLL(Node *head, int n)
{
    if (n == 0)
        return head;

    int count = 0;
    Node *curr = head;
    while (count < n - 1 && curr != NULL) //Move pointer to prev to Nth Node
    {
        curr = curr->next;
        count++;
    }

    if (curr == NULL) //Nth Node doew not exist
        return head;

    Node *NthNode = curr;

    while (curr->next != NULL)
        curr = curr->next;

    curr->next = head; //Link last and first node
    head->prev = curr;

    head = NthNode->next; //Reallocate head

    NthNode->next = NULL; //Break link of NthNode and
    head->prev = NULL;    //its previous Node

    return head;
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

        int num;
        cin >> num;
        head = rotateDLL(head, num);
        cout << "DLL After rotation : ";
        displayList(head);
    }
    return 0;
}