#include<bits/stdc++.h>

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

// TC - O(N)... SC - O(N)...
vector<int> diagonal(Node *root)
{
    vector<int> v;
    if(root == NULL)
        return v;
    
    queue<Node*> pending;
    
    pending.push(root);
    
    while(pending.size() != 0)
    {
        Node* front = pending.front();
        pending.pop();
        while(front)
        {
            if(front->left)
                pending.push(front->left);
            v.push_back(front->data);
            
            front = front->right;
        }
    }
    return v;
}