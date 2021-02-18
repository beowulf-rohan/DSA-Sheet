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
int KthSmallestElement(Node *root, int k)
{
    Node* curr = root;
    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            k--;
            if(k == 0)
                return curr->data;
            curr = curr->right;
        }
        else
        {
            Node* pre = curr->left;
            while(pre->right != curr && pre->right != NULL)
            {
                pre = pre->right;
            }
            
            if(pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                pre->right = NULL;
                k--;
                if(k == 0)
                    return curr->data;
                curr = curr->right;
            }
        }
    }
    return -1;
}

// SC - O(n).... TC - O(h)....
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