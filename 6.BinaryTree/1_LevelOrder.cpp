#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};


vector<int> levelOrder(Node* node)
{
    vector<int> v;
    if(node == NULL)
        return v;
    
      queue<Node*> pending;
  
    pending.push(node);
    v.push_back(node->data);
  
    while(pending.size() != 0)
    {
        Node* front = pending.front();
        pending.pop();
      
        if(front->left != NULL)
            pending.push(front->left);
        if(front->right != NULL)
            pending.push(front->right);
    }
  return v;
}