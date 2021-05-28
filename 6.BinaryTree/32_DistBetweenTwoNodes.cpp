#include<bits/stdc++.h>
#include<vector>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};


//TC - O(n).... SC - O(h)....
Node* LCA(Node* root, int a, int b)
{
    if(!root)
        return NULL;
    
    if(root->data == a || root->data == b)
        return root;
    
    Node* leftNode = LCA(root->left, a, b);
    Node* rightNode = LCA(root->right, a, b);
    
    if(leftNode && rightNode)
        return root;
    else if(leftNode)
        return leftNode;
    else
        return rightNode;
}

int find(Node* root, int x)
{
    if(!root)
        return -1;
    
    if(root->data == x)
        return 0;
    
    int l = find(root->left, x);
    int r = find(root->right, x);
    
    if(l == -1 && r == -1)
        return -1;
    else if(l != -1)
        return l+1;
    else
        return r+1;
}

int findDist(Node* root, int a, int b) 
{
    Node* lca = LCA(root, a, b);
    
    int d1 = find(lca, a);
    int d2 = find(lca, b);
    
    return d1+d2;
}