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


void getCount(Node* root, int l, int h, int &count)
{
    if(root == NULL)
        return;
    
    getCount(root->left, l, h, count);
    
    if(root->data >= l && root->data <= h)
        count++;
    
    getCount(root->right, l, h, count);
}

int getCount(Node *root, int l, int h)
{
  int count = 0;
  getCount(root, l, h, count);
  return count;
}