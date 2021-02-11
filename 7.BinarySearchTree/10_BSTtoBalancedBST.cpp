#include<iostream>
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


// SC - O(n).... TC - O(n)....
void inorder(Node* root, vector<Node*> &nodes)
{
    if(root == NULL)
        return;
    
    inorder(root->left, nodes);
    nodes.push_back(root);
    inorder(root->right, nodes);
}
    
Node* buildTree(vector<Node*> nodes, int si, int ei)
{
    if(si > ei)
        return NULL;
    
    int mid = (si+ei)/2;
        
    Node* root = nodes[mid];
    root->left = buildTree(nodes, si, mid-1);
    root->right = buildTree(nodes, mid+1, ei);
        
    return root;
}

Node* balanceBST(Node* root)
{
    vector<Node*> nodes;
    inorder(root, nodes);
        
    return buildTree(nodes, 0, nodes.size()-1);
}