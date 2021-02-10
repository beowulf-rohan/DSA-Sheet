#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// TC - O(h).... SC - O(h)....
Node* findLCA(Node* root, int n1, int n2)
{
    if(root == NULL)
       return NULL;
    
    if(root->data == n1 || root->data == n2)
        return root;
        
    Node* l;
    Node* r;
    
    if(n1 < root->data)
        l = findLCA(root->left, n1, n2);
    else
        l = findLCA(root->right, n1, n2);
     
    if(n2 > root->data)
        r = findLCA(root->left, n1, n2);
    else
        r = findLCA(root->right, n1, n2);
    if(l != NULL && r != NULL)
        return root;
    if(l != NULL)
        return l;
    else
        return r; 
}

// TC - O(h).... SC - O(h)....
Node* findLCA(Node* root, int n1, int n2)
{
    if(root == NULL)
       return NULL;
    
    if(root->data > n1 && root->data > n2)
        return findLCA(root->left, n1, n2);
    if(root->data < n1 && root->data < n2)
        return findLCA(root->right, n1, n2);
    
    return root;
}


Node* LCA(Node *root, int n1, int n2)
{
   return findLCA(root, n1, n2);
}