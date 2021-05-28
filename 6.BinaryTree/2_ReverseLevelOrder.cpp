#include <bits/stdc++.h>
#include<stack>
#include<queue>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

vector<int> reverseLevelOrder(Node *root)
{
    vector<int> v;
    if(root == NULL)
        return v;
    
    queue<Node*> q;
    stack<Node*> s;
  
    q.push(root);
  
    while(q.size() != 0)
    {
        Node* front = q.front();
        q.pop();
        s.push(front);
        
        if(front->right != NULL)
            q.push(front->right);
      
        if(front->left != NULL)
            q.push(front->left);
    }
    
    while(s.size() != 0)
    {
        Node* node = s.top();
        s.pop();
        v.push_back(node->data);
    }
  return v;
}