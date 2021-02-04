#include<bits/stdc++.h>

using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


void DLL(Node* root, Node* &head, Node* &prev)
{
    if(root == NULL)
        return;
    
    DLL(root->left, head, prev);
    
    if(head == NULL)
    {
        head = root;
        prev = root;
    }
    else
    {
        prev->right = root;
        prev->right->left = prev;
        prev = prev->right;
    }
    
    DLL(root->right, head, prev);
}

Node* bToDLL(Node *root)
{
    Node* head = NULL;
    Node* prev = NULL;
    DLL(root, head, prev);
    return head;
}