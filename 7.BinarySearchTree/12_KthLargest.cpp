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


// SC - O(h).... TC - O(n)....
Node* KthLargest(Node* root, int &k)
{
    if(root == NULL)
        return NULL;
    
    Node* r = KthLargest(root->right, k);
    if(r != NULL)
        return r;
    
    k--;
    if(k == 0)
        return root;
    
    Node* l = KthLargest(root->left, k);
    return l;
    
}

int kthLargest(Node *root, int K)
{
    Node* ans = KthLargest(root, K);
    if(ans == NULL)
        return -1;
    
    return ans->data;
}