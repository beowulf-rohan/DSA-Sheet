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

int minValue(Node* root)
{
    if(root->left == NULL)
        return root->data;
    
    minValue(root->left);
}


int maxValue(Node* root)
{
    if(root->right == NULL)
        return root->data;
    
    maxValue(root->right);
}