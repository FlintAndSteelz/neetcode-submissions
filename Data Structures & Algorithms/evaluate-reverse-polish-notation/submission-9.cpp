class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sotaikhoan;
        for (const auto& c: tokens){
            if (c=="+"){
                int b = sotaikhoan.top();
                sotaikhoan.pop();
                int a = sotaikhoan.top();
                sotaikhoan.pop();
                sotaikhoan.push(a+b);
            }
            else if (c =="-"){
                int b = sotaikhoan.top();
                sotaikhoan.pop();
                int a = sotaikhoan.top();
                sotaikhoan.pop();
                sotaikhoan.push(a-b);
            }
            else if (c =="*"){
                int b = sotaikhoan.top();
                sotaikhoan.pop();
                int a = sotaikhoan.top();
                sotaikhoan.pop();
                sotaikhoan.push(a*b);
            }
            else if (c=="/"){
                int b = sotaikhoan.top();
                sotaikhoan.pop();
                int a = sotaikhoan.top();
                sotaikhoan.pop();
                sotaikhoan.push(a/b);
            }
            else
                sotaikhoan.push(stoi(c));

        }
        return sotaikhoan.top();
    }
};
