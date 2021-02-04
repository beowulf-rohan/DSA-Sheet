#include <iostream>

using namespace std;

/* Link list Node */
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

int intersectPoint(struct Node *head1, struct Node *head2);

Node *inputList(int size)
{
    if (size == 0)
        return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node *head1 = inputList(n1);
        Node *head2 = inputList(n2);
        Node *common = inputList(n3);

        Node *temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

int findSize(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int intersectPoint(Node *head1, Node *head2)
{
    int size1 = findSize(head1);
    int size2 = findSize(head2);

    Node *temp1, *temp2;

    int d = (size1>size2) ? (size1-size2) : (size2-size1);        //abs(size1 - size2);
    temp1 = (size1 >= size2) ? head1 : head2;
    temp2 = (size1 < size2) ? head1 : head2;
    while (d--)
    {
        temp1 = temp1->next;
    }

    while (temp1 && temp2)
    {
        if (temp1 == temp2)
            return temp1->data;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return -1;
}
