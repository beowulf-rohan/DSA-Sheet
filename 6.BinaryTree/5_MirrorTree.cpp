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

// TC - O(n)...  Stack Space - O(Height of Tree)....
void mirror(Node* root) 
{
    if(root == NULL)
        return;
    
    mirror(root->left);
    mirror(root->right);
    
    swap(root->left, root->right);
    
}