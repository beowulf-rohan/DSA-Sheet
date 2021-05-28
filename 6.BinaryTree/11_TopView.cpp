#include<iostream>
#include<queue>
#include<map>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};

// TC - O(N)... SC - O(N)...
void topView(struct Node *root)
{
    if(root == NULL)
        return;
    
    queue<pair<Node*, int>> pending;
    map<int, int> mp;
    
    pending.push({root, 0});
    
    while(pending.size() != 0)
    {
        Node* front = pending.front().first;
        int height = pending.front().second;
        
        pending.pop();
        
        if(!mp[height])
            mp[height] = front->data;
            
        if(front->left)
            pending.push({front->left, height-1});
        if(front->right)
            pending.push({front->right, height+1});
    }
    
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->second << " ";
    } 
}