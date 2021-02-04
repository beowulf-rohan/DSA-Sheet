#include<iostream>
#include<vector>
#include<queue>

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
vector<int> leftView(Node *root)
{
    vector<int> v;
   
    if(root == NULL)
        return v;
    
    queue<Node*> pending;
    pending.push(root);
    
    while(pending.size() != 0)
    {
        int size = pending.size();
        v.push_back(pending.back()->data);
        while(size--)
        {
            Node* front = pending.front();
            pending.pop();
            if(front->left)
                pending.push(front->left);
            if(front->right)
                pending.push(front->right);
        }
    }
    return v;
}