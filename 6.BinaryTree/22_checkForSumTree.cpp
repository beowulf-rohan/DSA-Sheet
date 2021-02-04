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

// TC - O(n)... SC - O(logn)...
int sumTree(Node* root, bool &isTrue)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return root->data;
    
    int l = sumTree(root->left, isTrue);
    int r = sumTree(root->right, isTrue);
    
    if(l+r != root->data)
        isTrue = false;
    
    return root->data + l + r;
}
bool isSumTree(Node* root)
{
    bool isTrue = true;
    sumTree(root, isTrue);
    return isTrue;
}