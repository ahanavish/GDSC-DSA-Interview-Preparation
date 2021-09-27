//https://leetcode.com/problems/min-stack/

class MinStack {
public:
    vector <int> v;
    MinStack() {
        
    }
    
    void push(int val) {
       v.push_back(val); 
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v[v.size()-1];
    }
    
    int getMin() {
        int min = v[0];
        for(int i=1; i<v.size(); i++)
            if(v[i] < min)
                min = v[i];
        return min;
    }
};