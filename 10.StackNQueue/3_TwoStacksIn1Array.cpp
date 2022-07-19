class TwoStack {
public:
    int* arr;
    int top1, top2, size;

public:
    TwoStack(int s) 
    {
        arr = new int[s];
        size = s;
        top1 = -1;
        top2 = size;
    }
    
    void push1(int num) 
    {
        if(top2 == 1+top1)
            return;
        top1++;
        arr[top1] = num;
    }

    void push2(int num) 
    {
        if(top2-1 == top1)
            return;
        top2--;
        arr[top2] = num;
    }

    int pop1() 
    {
        if(top1 == -1)
            return -1;
        int x = arr[top1];
        top1--;
        return x;
    }

    int pop2() 
    {
        if(top2 == size)
            return -1;
        int x = arr[top2];
        top2++;
        return x;
    }
};
