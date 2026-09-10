class MinStack {
    stack<int> stk1;
    stack<int> stk2;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk1.push(val);
        if (!stk2.empty()){
            if (val <= stk2.top())
                stk2.push(val);
            else
                stk2.push(stk2.top());
        }
        else
            stk2.push(val);
    }
    
    void pop() {
        stk1.pop();
        stk2.pop();
    }
    
    int top() {
        return stk1.top();
    }
    
    int getMin() {
        return stk2.top();
    }
};
