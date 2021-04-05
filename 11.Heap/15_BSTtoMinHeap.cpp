#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

void inorder(Node* root, vector<int> &v)
{
    if(root == NULL)
        return;
    
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}


void storeData(Node* root, vector<int> &arr, int &i)
{
    if(root == NULL)
        return;
    
    root->data = arr[i++];
    storeData(root->left, arr, i);
    storeData(root->right, arr, i);
}

Node* convertBSTtoMinHeap(Node* root)
{
    vector<int> arr;
    inorder(root, arr);

    int i = 0;
    storeData(root, arr, i);

    return root;
}