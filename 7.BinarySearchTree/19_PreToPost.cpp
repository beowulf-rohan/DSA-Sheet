#include<bits/stdc++.h>

using namespace std;


struct Node 
{
    int data;
    Node* right;
    Node* left;
    
};


Node* getNewNode(int val)
{
    Node* root = new Node;
    root->data = val;
    root->left = NULL;      root->right = NULL;
    return root;
}

int preToPost(int* pre, Node* root, int pos, int size, int min, int max)
{
    if(pos == size || pre[pos] < min || pre[pos] > max)
        return pos;
    
    if(pre[pos] < root->data)
    {
        root->left = getNewNode(pre[pos]);
        pos++;
        pos = preToPost(pre, root->left, pos, size, min, root->data-1);
    }
    
    if(pos == size || pre[pos] < min || pre[pos] > max)
        return pos;
    
    if(pre[pos] > root->data)
    {
        root->right = getNewNode(pre[pos]);
        pos++;
        pos = preToPost(pre, root->right, pos, size, root->data+1, max);
    }
    return pos;
}

Node* constructTree(int *pre, int size)
{
    Node* root = NULL;
    if(size == 0)
        return root;
        
    root = getNewNode(pre[0]);
    if(size == 1)
    {
        return root;
    }
    
    preToPost(pre, root, 1, size, INT_MIN, INT_MAX);
    
    return root;
}
