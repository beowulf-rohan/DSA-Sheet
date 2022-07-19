#include<bits/stdc++.h>
using namespace std;
 class Node
{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node* merge(Node* l1, Node* l2)
{
    Node dummy(-1);
    Node* ptr = &dummy;
    while(l1 && l2)
    {
        if(l1->data <= l2->data)
        {
            ptr->next = l1;
            l1 = l1->next;
        }
        else
        {
            ptr->next = l2;
            l2 = l2->next;
        }
        ptr = ptr->next;
    }
    if(l1) ptr->next = l1;
    else ptr->next = l2;
    return dummy.next;
}

Node* getMid(Node* head)
{
    Node* prevMid = NULL;
    while(head && head->next)
    {
        prevMid = (prevMid == NULL) ? head : prevMid->next;
        head = head->next->next;
    }
    
    Node* mid = prevMid->next;
    prevMid->next = NULL;
    return mid;
}

Node* mergeSort(Node *head) 
{
    if(!head || !head->next)
        return head;
    
    Node* mid = getMid(head);
    Node* left = mergeSort(head);
    Node* right = mergeSort(mid);
    return merge(left, right);
}
