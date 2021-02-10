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


Node* kthAnces(Node* root, int &k, int node, int &ans)
{
    if(root == NULL)
        return NULL;
    
    if((root->data == node) || kthAnces(root->left, k, node, ans) || kthAnces(root->right, k, node, ans))
    {
        if(k > 0)
        {
            k--;
            return root;
        }
        else
        {
            ans = root->data;
            return NULL;
        }
    }
}

int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;
    
    kthAnces(root, k, node, ans);
    
    return ans;
}
