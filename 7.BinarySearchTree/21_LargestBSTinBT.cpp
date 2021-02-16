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


struct P
{
    int size, min, max;
    bool isBST;
};

P findSize(Node* root)
{
    if(root == NULL)
    {
        P temp;
        temp.isBST = true;      temp.size = 0;
        temp.min = INT_MAX;     temp.max = INT_MIN;
        return temp;
    }
    
    if(root->left == NULL && root->right == NULL)
    {
        P temp;
        temp.isBST = true;      temp.size = 1;
        temp.min = root->data;  temp.max = root->data;
        return temp;
    }
    
    P leftData = findSize(root->left);
    P rightData = findSize(root->right);
    
    P temp;
    if(leftData.isBST && rightData.isBST && root->data > leftData.max && root->data < rightData.min)
    {
        temp.size = 1 + leftData.size + rightData.size;
        temp.min = min(root->data, min(leftData.min, rightData.min));
        temp.max = max(root->data, max(leftData.max, rightData.max));
        temp.isBST = true;
        
        return temp;
    }
    
    temp.size = max(leftData.size, rightData.size);
    temp.isBST = false;
    
    return temp;
}

int largestBst(Node *root)
{
	return findSize(root).size;
}