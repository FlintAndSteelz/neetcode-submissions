class MinStack {
private: 
    stack<int> stk;
    stack<int> minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if (minStack.empty()){
            minStack.push(val);
            return;
        } 
        val = min(val, minStack.top());
        minStack.push(val);
    }
    
    void pop() {
        stk.pop();
        minStack.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
