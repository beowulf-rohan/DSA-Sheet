#include<bits/stdc++.h>

using namespace std;


struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

// TC - O(h).... SC - O(h)....
bool search(Node* root, int x)
{
    if(root == NULL)
        return false;
    
    if(root->data == x)
        return true;
    
    if(root->data > x)
        search(root->left, x);
    else if(root->data < x)
        search(root->right, x);
}