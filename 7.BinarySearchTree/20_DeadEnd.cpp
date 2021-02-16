#include<bits/stdc++.h>

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

// TC - O(n).... SC - O(h)....
bool deadEnd(Node* root, int min, int max)
{
    if(root == NULL)
        return false;
    
    if(min == max)
       return true;
    
    bool leftData = deadEnd(root->left, min, root->data-1);
    bool rightData = deadEnd(root->right, root->data+1, max);
    
    return leftData | rightData;
}

bool isDeadEnd(Node *root)
{
    return deadEnd(root, 1, INT_MAX);
}