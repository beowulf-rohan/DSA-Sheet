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


//Recursive...
void postorder(Node* root)
{
    if(root == NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
}


//Iterative...
#include<stack>
void preOrder(Node* root)
{
    if(root == NULL)
        return;
    
    stack<int> out;
    stack<Node*> st;

    st.push(root);
   
    while(!st.empty())
    {
        Node *curr = st.top();
        st.pop();
 
        out.push(curr->data);
        
        if (curr->left)
            st.push(curr->left);
 
        if (curr->right)
            st.push(curr->right);
    }
    
    while(!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }

}