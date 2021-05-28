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


struct BST
{
    int min, max, size;
    bool isBST;
};

BST findBST(Node* root)
{
    if(root == NULL)
	{
	    BST p;
	    p.min = INT_MAX;    p.max = INT_MIN;
	    p.isBST = true;     p.size = 0;
	    return p;
	}
	
	if(root->left == NULL && root->right == NULL)
	{
	    BST p;
	    p.min = root->data;    p.max = root->data;
	    p.isBST = true;     p.size = 1;
	    return p;
	}
	
	BST l = findBST(root->left);
	BST r = findBST(root->right);
	
	BST p;
	if(l.isBST && r.isBST && root->data > l.max && root->data < r.min)
	{
	    p.min = min(root->data, l.min);    
	    p.max = max(root->data, r.max);
	    p.isBST = true;
	    p.size = 1 + l.size + r.size;
	    return p;
	}
	p.size = max(l.size, r.size);
	p.isBST = false;
	return p;
}

int largestBst(Node *root)
{
	return findBST(root).size;
}