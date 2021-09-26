// https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
    queue<int> q1, q2;
public:
    MyStack() 
    {
        
    }
    
    void push(int x)
    {
        q1.push(x);
        
        while(!q2.empty())
        {
        q1.push(q2.front());
        q2.pop();
        }
        
        swap(q1, q2);
    }
    
    int pop()
    {
        int x = q2.front();
        q2.pop();
        return x;
    }
    
    int top()
    {
        return q2.front();
    }
    
    bool empty()
    {
        if(q2.size() == 0)
            return true;
        else
            return false;
    }
};
