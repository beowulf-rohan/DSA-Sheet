#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

//TC - O(n)

#include<queue>

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
        {
            pending.push(front->left);
            v.push_back(front->left->data);
        }
        if(front->right != NULL)
        {
            pending.push(front->right);
            v.push_back(front->right->data);
        }
    }
  return v;
}

void inOrder(struct Node* node)
{
  if (node == NULL)
    return;

  inOrder(node->left);
  printf("%d ", node->data);

  inOrder(node->right);
}


Node* buildTree(string str)
{   
    
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    Node* root = newNode(stoi(ip[0]));
        
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

int main()
{
  int t;
  scanf("%d ",&t);
  while (t--)
  {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
        vector <int> res = levelOrder(root);
        for (int i : res) cout << i << " ";
        cout << endl;
  }
  return 0;
}