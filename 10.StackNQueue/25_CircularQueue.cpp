#include<bits/stdc++.h>
using namespace std;

class Queue
{
    private :   int* data;
                int size, nextIndex, firstIndex, capacity;
    public  :   Queue(int s)
                {
                    data = new int[s];
                    size = 0;
                    nextIndex = 0;
                    firstIndex = -1;
                    capacity = s;
                }

                void enqueue(int x)
                {
                    if(size == capacity)
                    {
                        cout << "Overflow"  << endl;
                        return;
                    }
                    data[nextIndex] = x;
                    
                    nextIndex = (nextIndex+1)%capacity;
                    size++;

                    if(firstIndex == -1)
                        firstIndex = 0;
                }

                void dequeue()
                {
                    if(size == 0)
                    {
                        cout << "Underflow"  << endl;
                        return;
                    }
                    
                    firstIndex = (firstIndex+1)%capacity;
                    size--;
                    if(size == 0)
                    {
                        firstIndex = -1;
                        nextIndex = 0;
                    }
                }

                int front()
                {
                    if(size == 0)
                        return -1;
                    return data[firstIndex];
                }

                int queueSize()
                {
                    return size;
                }

                bool isEmpty()
                {
                    return (size == 0);
                }

                void free()
                {
                    delete [] data;
                }
};

int main()
{
    Queue ob(5);
    
    while(true)
    {
        int ch;
        cin >> ch;

        if(ch == 1)
        {
            int val;
            cin >> val;
            ob.enqueue(val);
        }
        else if(ch == 2)
            ob.dequeue();
        else if(ch == 3)
            cout << ob.front() << endl;
        else if(ch == 4)
            cout << ob.isEmpty() << endl;
        else if(ch == 5)
            cout << ob.queueSize() << endl;
        else
            break;
    }
    ob.free();
    return 0;
}