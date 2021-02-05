#include<iostream>

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

bool solve(Node* root, int h, int &maxHt)
{
    if(root == NULL)
        return true;
        
    if(root->left == NULL && root->right == NULL)
    {
        if(maxHt == -1)
        {
            maxHt = h;
            return true;
        }
        else
        {
            return (maxHt == h);
        }
    }
    
    return solve(root->left, h+1, maxHt) & solve(root->right, h+1, maxHt);
}


bool check(Node *root)
{
    int maxHt = -1;
    return solve(root, 0, maxHt);
}