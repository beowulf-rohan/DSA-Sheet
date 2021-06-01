#include <iostream>
#include<stack>
using namespace std;

class Node
{
    public:   int data;    
                Node *next;
    public:    Node(int data)
                {
                    this->data = data;
                    next = NULL;
                }
};

Node* reverse(struct Node *head, int k)
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


Node* reverse(Node* head, int k)
{
    stack<Node*> st;
    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL)
    {
        int count = 0;
        while (curr != NULL && count < k)
        {
            st.push(curr);
            curr = curr->next;
            count++;
        }

        while(st.size() > 0)
        {
            if(prev == NULL)
            {
                prev = st.top();
                head = st.top();
            }
            else
            {
                prev->next = st.top();
                prev = prev->next;
            }
            st.pop();
        }
    }
    prev->next = NULL;
    return head;
}