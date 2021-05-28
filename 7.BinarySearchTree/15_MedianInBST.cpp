#include<iostream>
#include<vector>

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

// TC - O(n).... SC - O(1)....
int countNodes(Node* root)
{
    int count = 0;
    Node* curr = root;
    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            count++;
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
                count++;
                curr = curr->right;
            }
        }
    }
    return count;
}


float median(Node* root)
{
    Node *prev;
    Node* curr = root;
    int count = 0;
    int countTotal = countNodes(root);
    
    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            count++;
            if((countTotal%2 != 0) && (count == (countTotal+1)/2))
                return prev->data;
            else if((countTotal%2 == 0) && (count == (countTotal/2)+1))
                return (prev->data + curr->data)/2;
                
            prev = curr;    
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
                prev = pre;
                count++;
                
                if((countTotal%2 != 0) && (count == (countTotal+1)/2))
                    return curr->data;
                else if((countTotal%2 == 0) && (count == (countTotal/2)+1))
                    return (prev->data+curr->data)/2;
                
                prev = curr;    
                curr = curr->right;
            }
        }
    }
}