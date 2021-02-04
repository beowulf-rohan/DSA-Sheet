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


//TC - O(n)....
int height(Node* node)
{
    if(node == NULL)
        return 0;
    return 1+max(height(node->left), height(node->right));
}

int diameter(Node* root)
{
    if(root == NULL)
        return 0;
    
    int op1 = 1 + height(root->left) + height(root->right);
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return max(op1, max(op2, op3));
}