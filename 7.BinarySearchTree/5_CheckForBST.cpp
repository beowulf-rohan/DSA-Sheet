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


bool checkBST(Node* root, int min, int max)
{
    if(root == NULL)
        return true;
    
    if(root->data < min || root->data > max)
        return false;
    
    return checkBST(root->left, min, root->data-1)&checkBST(root->right, root->data+1, max);
}

bool isBST(Node* root) {
    return checkBST(root, INT_MIN, INT_MAX);
}