class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0, currSum = 0;
        unordered_map<int,int> prefixSum;
        prefixSum[0] = 1;
        for (auto num: nums){
            currSum += num;
            int diff = currSum - k;
            result += prefixSum[diff];
            prefixSum[currSum]++;
        }
        return result;
    }
};