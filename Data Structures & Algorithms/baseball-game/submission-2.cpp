class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> record;
        int result = 0;
        for (const string& charr: operations){
            if (charr =="+"){
                int top = record.top();
                record.pop();
                int newTop = top + record.top();
                record.push(top);
                record.push(newTop);
                result += newTop;
            }
            else if (charr == "C"){
                result -= record.top();
                record.pop();
            }
            else if (charr == "D"){
                record.push(2*record.top());
                result += record.top();
            }
            else{
                record.push(stoi(charr));
                result += record.top();
            }
        }
        return result;
    }
};