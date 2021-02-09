#include<bits/stdc++.h>
#include<vector>

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


Node* lca(Node* root ,int n1 ,int n2 )
{
    if(root == NULL)
        return NULL;
    if(root->data == n1 || root->data == n2)
        return root;
    
    Node* leftNode = lca(root->left, n1, n2);
    Node* rightNode = lca(root->right, n1, n2);
    
    if(leftNode != NULL && rightNode != NULL)
        return root;
    
    if(leftNode != NULL)
        return leftNode;
    else
        return rightNode;
    
    
}