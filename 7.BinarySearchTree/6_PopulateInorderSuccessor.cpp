#include<bits/stdc++.h>

using namespace std;


struct Node {
    int data;
    Node* right;
    Node* left;
    Node* next;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
        next = NULL;
    }
};


// TC - O(n).... SC - O(h)....
void populate(Node* root, Node* &prev)
{
    if(root == NULL)
        return;
    
    populate(root->left, prev);
    
    if(prev != NULL)
        prev->next = root;
    
    prev = root;
    
    populate(root->right, prev);
}

void populateNext(struct Node* root)
{
    Node* prev = NULL;
    populate(root, prev);
}