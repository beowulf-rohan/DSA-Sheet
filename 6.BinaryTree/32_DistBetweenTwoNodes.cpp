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
Node* lca(Node* root, int a, int b)
{
    if(root == NULL)
        return root;
    if(root-> data == a || root->data == b)
        return root;
    
    Node* leftNode = lca(root->left, a, b);
    Node* rightNode = lca(root->right, a, b);
    
    if(leftNode != NULL && rightNode != NULL)
        return root;
    
    if(leftNode != NULL)
        return leftNode;
    else
        return rightNode;
}

int findNode(Node* root, int x)
{
    if(root == NULL)
        return 0;
    if(root->data == x)
        return 1;
    
    int l = findNode(root->left, x);
    int r = findNode(root->right, x);
    
    if(l == 0 && r == 0)
        return 0;
    return l+r+1;
}

int findDist(Node* root, int a, int b) 
{
    Node* LCA = lca(root, a, b);
    
    int leftCount = findNode(LCA, a);
    int rightCount = findNode(LCA, b);
    
    return leftCount+rightCount-2;
}