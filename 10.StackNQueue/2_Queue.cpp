#include<iostream>
using namespace std;

class Node {
    public  :   int data;
                Node* next;
    public  :   Node(int data) 
                {
                    this->data = data;
                    next = NULL;
                }
};

class queue {
    public  :   int size;
                Node* front;
                Node* back;
    public  :   queue()
                {
                    front = NULL;   back = NULL;
                    size = 0;
                }

                void enqueue()
                {
                    int data;
                    cin >> data;

                    Node* newNode = new Node(data);
                    if(front == NULL)
                    {
                        front = newNode;    back = newNode;
                    }
                    else
                    {
                        back->next = newNode;
                        back = newNode;
                    }
                    size++;
                }

                void dequeue()
                {
                    if(front == NULL)
                    {
                        cout << "Underflow\n";
                        return;
                    }

                    cout << front->data << " deleted" << endl;
                    Node* toDelete = front;
                    front = front->next;
                    toDelete->next = NULL;
                    delete toDelete;
                    size--;
                }

                void getFront()
                {
                    if(front == NULL)
                    {
                        cout << "Underflow\n";
                        return;
                    }
                    cout << front->data << endl;
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
