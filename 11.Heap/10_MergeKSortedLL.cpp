#include <bits/stdc++.h>
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

typedef pair<int, Node*> pp;

Node* mergeKLists(Node *arr[], int k)
{
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    Node* head = NULL, *tail = NULL;
           
    for(int i = 0; i < k; i++)
    {
        pq.push({arr[i]->data, arr[i]});
    }
    
    while(pq.size() != 0)
    {
        pp curr = pq.top();
        pq.pop();
               
        if(head == NULL)
        {
            head = curr.second;
            tail = curr.second;
        }
        else
        {
           tail->next = curr.second;
            tail = tail->next;
        }               

        if(curr.second->next != NULL)
        {
            Node* toPush = curr.second->next;
            curr.second->next = NULL;
            pq.push({toPush->data, toPush});
        }
    }

    return head;
}