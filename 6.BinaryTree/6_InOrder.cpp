#include<iostream>

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

//Morris Traversal....
void inOrder(Node* root)
{   
    Node* curr = root;
    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            Node* pre = curr->left;
            while(pre->right != NULL && pre->right != curr)
                pre = pre->right;
            
            if(pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                pre->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}


// Recursive ...
void inOrder(Node* root)
{
    if(root == NULL)
        return;
    
    if(root->left)
        inOrder(root->left);
    
    cout << root->data << " ";
    
    if(root->right)
        inOrder(root->right);
}


// Iterative....
#include<stack>
void inOrder(Node* root)
{
    stack<Node*> st;
    Node* curr = root;
    while(!st.empty() || curr != NULL)
    {
        if(curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = st.top();
            st.pop();

            cout << curr->data << " ";
            curr = curr->right;
        }
    }
}