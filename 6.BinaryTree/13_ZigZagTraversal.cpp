#include<bits/stdc++.h>
#include<queue>
#include<vector>

using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// TC - O(N)... SC - O(N)...
vector <int> zigZagTraversal(Node* root)
{
    vector<int> v;
	if(root == NULL)
	    return v;
	
	queue<Node*> pending;    
	int height = 0;
	
	pending.push(root);
	
	while(pending.size() != 0)
	{
	    int size = pending.size();
	    vector<int> temp;
	    while(size--)
	    {
	        Node* front = pending.front();
	        pending.pop();
	        
	        temp.push_back(front->data);
	        
	        if(front->left)
	            pending.push(front->left);
	        if(front->right)
	            pending.push(front->right);
	    }
	    
	    if(height%2 != 0)
	        reverse(temp.begin(), temp.end());
	   
	    height++;
	    
	    for(int i = 0; i < temp.size(); i++)
	    {
	        v.push_back(temp[i]);
	    }
	}
	
	return v; 
}