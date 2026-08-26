class Solution {
public:
    bool isValid(string s) {
        stack<char> parenthesis;
        int n = s.length();
        for (const auto charr: s){
            if (charr == '[' || charr == '{' || charr == '(')
                parenthesis.push(charr);
            else if (charr == ')'){
                if (parenthesis.empty() == true ||parenthesis.top() != '(') return false;
                parenthesis.pop();
            }
            else if (charr == ']'){
                if (parenthesis.empty() == true ||parenthesis.top() != '[') return false;
                parenthesis.pop();
            }
            else if (charr == '}'){
                if (parenthesis.empty() == true ||parenthesis.top() != '{') return false;
                parenthesis.pop();
            }
            
        }
        return parenthesis.empty();
    }
};
