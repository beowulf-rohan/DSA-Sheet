#include<iostream>

using namespace std;

class Node{
    public  :   int data;
                Node* next;
    
                Node(int data)
                {
                    this->data = data;
                    next = NULL;
                }
};

class stack{
    public  :   Node* top;
                int size;

    public  :   stack()
                {
                    top = NULL;
                    size = 0;
                }
    
                void push()
                {
                    int x;
                    cin >> x;
                    Node* newNode = new Node(x);

                    newNode->next = top;
                    top = newNode;
                    size++;
                }

                void pop()
                {
                    if(top == NULL)
                    {
                        cout << "Underflow\n";
                        return;
                    }
                    
                    cout << top->data << " deleted\n";
                    Node* toDelete = top;
                    top = top->next;
                    toDelete->next = NULL;
                    delete toDelete;
                    size--;
                }

                void getTop()
                {
                    if(top == NULL)
                    {
                        cout << "Underflow\n";
                        return;
                    }
                    cout << top->data << endl;
                }

                void isEmpty()
                {
                    cout << (size == 0) << endl;
                }

                void getSize()
                {
                    cout << size << endl;
                }
};

