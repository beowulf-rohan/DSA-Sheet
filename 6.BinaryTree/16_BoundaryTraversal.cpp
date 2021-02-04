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

// TC - O(n)... SC - O(ht of tree)...
void leftNode(Node* root, vector<int> &v)
{
    if(root == NULL)
        return;
    
    if(root->left)
    {
        v.push_back(root->data);
        leftNode(root->left, v);
    }
    else if(root->right)
    {
        v.push_back(root->data);
        leftNode(root->right, v);
    }
}

void leafNode(Node* root, vector<int> &v)
{
    if(root == NULL)
        return;
    
    leafNode(root->left, v);
    
    if(!root->left && !root->right)
        v.push_back(root->data);
    
    leafNode(root->right, v);
}

void rightNode(Node* root, vector<int> &v)
{
    if(root == NULL)
        return;
    
    if(root->right)
    {
        rightNode(root->right, v);
        v.push_back(root->data);
    }
    else if(root->left)
    {
        rightNode(root->left, v);
        v.push_back(root->data);
    }
}

vector <int> printBoundary(Node *root)
{
     vector<int> v;
     
     if(root == NULL)
        return v;
     
     v.push_back(root->data);
     
     leftNode(root->left, v);
     leafNode(root, v);
     rightNode(root->right, v);
     
     return v;
}