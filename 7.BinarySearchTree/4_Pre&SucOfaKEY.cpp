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


// TC - O(n).... SC - O(h)....
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root == NULL)
        return;
    
    if(root->data == key)
    {
        Node* preItr = root->left;
        while(preItr)
        {
            pre = preItr;
            preItr = preItr->right;
        }

        Node* sucItr = root->right;
        while(sucItr)
        {
            suc = sucItr;
            sucItr = sucItr->left;
        }
        return;
    }
    
    else if(root->data > key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    
    else if(root->data < key)
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}