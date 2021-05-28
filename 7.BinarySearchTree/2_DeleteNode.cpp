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
    if(!root)
        return NULL;
        
    //Key node is in the left tree....
    if(root->data > key)
    {
        root->left = deleteNode(root->left, key);
        return root;
    }
    //Key node is in the right tree....
    else if(root->data < key)
    {
        root->right = deleteNode(root->right, key);
        return root;
    }
    //Key node found....
    else
    {
        //Key node is a Leaf node....
        if(!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        //Key Node is a node with no left branch....
        else if(!root->left)
        {
            Node* temp = root->right;
            root->right = NULL;
            delete root;
            return temp;
        }
        //Key Node is a node with no right branch....
        else if(!root->right)
        {
            Node* temp = root->left;
            root->left == NULL;
            delete root;
            return temp;
        }
        //Key Node is a node with right and left branch....
        else
        {
            Node* minNode = root->right;
            while(minNode->left != NULL)
            {
                minNode = minNode->left;
            }
            int minNodeData = minNode->data;
            root->data = minNodeData;
            root->right = deleteNode(root->right, minNodeData);
            return root;
        }    
    }
}