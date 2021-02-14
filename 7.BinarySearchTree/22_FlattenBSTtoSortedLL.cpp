#include<iostream>

using namespace std;


struct Node 
{
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};


void flattenToLL(Node* root, Node* &prev)
{
    if(root == NULL)
        return;
        
    flattenToLL(root->right, prev);
    flattenToLL(root->left, prev);
        
    root->right = prev;
    root->left = NULL;
    prev = root;
}
    
void flatten(Node* root)
{
    Node* prev = NULL;
    flattenToLL(root, prev);        
}