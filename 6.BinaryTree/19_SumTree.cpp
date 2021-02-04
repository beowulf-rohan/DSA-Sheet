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

// TC - O(N)... SC - O(ht of tree)...
int sumTree(Node* root)
{
    if(root == NULL)
        return 0;
    
    int l = sumTree(root->left);
    int r = sumTree(root->right);
    
    int curr = root->data;
    
    root->data = l+r;
    return l+r+curr;
}

void toSumTree(Node *root)
{
    sumTree(root);
}  