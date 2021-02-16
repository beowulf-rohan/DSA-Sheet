#include<bits/stdc++.h>

using namespace std;


struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};


Node* deleteNode(Node* root, int key)
{
    if(root == NULL)
        return NULL;
        
    if(root->data > key)
    {
        root->left = deleteNode(root->left, key);
        return root;
    }
    
    else if(root->data < key)
    {
        root->right = deleteNode(root->right, key);
        return root;
    }
        
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
            
        else if(root->left = NULL)
        {
            Node* temp = root->right;
            root->right = NULL;
            delete root;
            return temp;
        }
            
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            root->left = NULL;
            delete root;
            return temp;
        }
            
        else
        {
            Node* minNode = root->right;
            while(minNode->left != NULL)
            {
                minNode = minNode->left;
            }
                
            int mindata = minNode->data;
            root->data = mindata;
            root->right = deleteNode(root->right, mindata);
            return root;
        }
    }
}