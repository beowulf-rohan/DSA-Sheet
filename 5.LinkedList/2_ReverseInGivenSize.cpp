#include <iostream>
#include<stack>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data)
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
        int num;
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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Node* reverse(Node* head, int k)
// {
//     stack<Node*> st;
//     Node* curr = head;
//     Node* prev = NULL;

//     while(curr != NULL)
//     {
//         int count = 0;
//         while (curr != NULL && count < k)
//         {
//             st.push(curr);
//             curr = curr->next;
//             count++;
//         }

//         while(st.size() > 0)
//         {
//             if(prev == NULL)
//             {
//                 prev = st.top();
//                 head = st.top();
//             }
//             else
//             {
//                 prev->next = st.top();
//                 prev = prev->next;
//             }
//             st.pop();
//         }
//     }
//     prev->next = NULL;
//     return head;
// }
Node *reverse (struct Node *head, int k)
{ 
    Node *curr = head, *after = NULL, *prev = NULL;
    int count = 0;
    while(curr != NULL && count < k)
    {
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
        count++;
    }
    
    if(after != NULL)
        head->next = reverse(after, k);
    return prev;
}

int main()
{
    Node *head = input();
    cout << "Linked List : ";
    print(head);

    int k;
    cin >> k;
    head = reverse(head, k);
    print(head);

    delete head;
    return 0;
}