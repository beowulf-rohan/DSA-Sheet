#include<iostream>

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

// SC - O(n).... TC - O(n)....
Node* KthSmallest(Node* root, int &k)
{
    if(root == NULL)
        return NULL;
    
    Node* l = KthSmallest(root->left, k);
    if(l != NULL)
        return l;
    
    k--;
    if(k == 0)
        return root;
    
    Node* r = KthSmallest(root->right, k);
    return r;
    
}

int KthSmallestElement(Node *root, int K)
{
    Node* ans = KthSmallest(root, K);
    if(ans == NULL)
        return -1;
    
    return ans->data;
}