class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char,char> closeToOpen{
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for (char c: s){
            if (closeToOpen.count(c)){
                if (stk.empty() == false && stk.top()== closeToOpen[c])
                    stk.pop();
                else 
                    return false;
                
            }
            else
                stk.push(c);
        }
        return stk.empty();
    }
};
