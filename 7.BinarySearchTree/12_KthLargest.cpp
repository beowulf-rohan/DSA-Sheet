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


// TC - O(n).... SC - O(1)....
int kthLargest(Node *root, int k)
{
    Node* curr = root;
    while(curr != NULL)
    {
        if(curr->right == NULL)
        {
            k--;
            if(k == 0)
                return curr->data;
            curr = curr->left;
        }
        else
        {
            Node* pre = curr->right;
            while(pre->left != NULL && pre->left != curr)
            {
                pre = pre->left;
            }
            
            if(pre->left == NULL)
            {
                pre->left = curr;
                curr = curr->right;
            }
            else
            {
                pre->left = NULL;
                k--;
                if(k == 0)
                    return curr->data;
                curr = curr->left;
            }
        }
    }
    return -1;
}

// SC - O(h).... TC - O(h)....
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