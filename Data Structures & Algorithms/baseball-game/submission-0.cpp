class Solution {
public:
    int calPoints(vector<string>& operations) {
        int score =0;
        stack<int> record;
        for (const string& charr: operations){
            if (charr == "+"){
                int temp1 = record.top();
                record.pop();
                int temp2 = record.top();
                record.push(temp1);
                record.push(temp1+temp2);
            }
            else if (charr == "D")
                record.push(record.top()*2);
            else if (charr == "C")
                record.pop();
            else    
                record.push(stoi(charr));
        }
        while (!record.empty()){
            score += record.top();
            record.pop();
        }
        return score;
    }
};