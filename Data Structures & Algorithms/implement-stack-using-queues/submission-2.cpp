class MyStack {
private:
    queue<int> que1, que2;
public:

    MyStack() {
        
    }
    
    void push(int x) {
        if (que1.empty() && que2.empty())
            que1.push(x);
        else if (!que1.empty() && que2.empty()){
            que2.push(x);
            while (!que1.empty()){
                que2.push(que1.front());
                que1.pop();
            }
        }
        else{
            que1.push(x);
            while (!que2.empty()){
                que1.push(que2.front());
                que2.pop();
            }            
        }
    }
    
    int pop() {
        if (!que2.empty())
        {
            int value = que2.front();
            que2.pop();
            return value;
        }
        int value = que1.front();
        que1.pop();
        return value;

    }
    
    int top() {
        if (!que2.empty())
        {
            int value = que2.front();
            return value;
        }
        int value = que1.front();
        return value;        
    }
    
    bool empty() {
        return que1.empty() && que2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */