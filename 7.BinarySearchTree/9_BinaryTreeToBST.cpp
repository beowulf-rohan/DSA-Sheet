#include<iostream>
#include<algorithm>
#include<vector>

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


void inorder(Node* root, vector<int> &nodes)
{
    if(root == NULL)
        return;
    
    inorder(root->left, nodes);
    nodes.push_back(root->data);
    inorder(root->right, nodes);
}

Node* buildTree(vector<int> &nodes, int si, int ei)
{
    if(si > ei)
        return NULL;
    
    int mid = (si+ei)/2;
    
    Node* root = new Node(nodes[mid]);
    root->left = buildTree(nodes, si, mid-1);
    root->right = buildTree(nodes, mid+1, ei);
    
    return root;
}

Node *binaryTreeToBST (Node *root)
{
    vector<int> nodes;
    
    inorder(root, nodes);
    sort(nodes.begin(), nodes.end());
    
    return buildTree(nodes, 0, nodes.size()-1);
}