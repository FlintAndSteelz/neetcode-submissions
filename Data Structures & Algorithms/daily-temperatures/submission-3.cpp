class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<pair<int,int>> stk;
        for (int i = 0; i < temperatures.size();++i){
            while (!stk.empty() && temperatures[i] > stk.top().first){
                auto pairr = stk.top();
                stk.pop();
                result[pairr.second] = i - pairr.second;
            }
            stk.push({temperatures[i], i});
        }
        return result;
    }
};
