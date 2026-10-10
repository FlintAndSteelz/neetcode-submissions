class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        for (int i = 0; i < n;++i){
            int maxRight = -1;
            for (int j = i+1; j < n;++j){
                maxRight = max(maxRight, arr[j]);
            }
            result[i] = maxRight;
        }
        return result;
    }
};