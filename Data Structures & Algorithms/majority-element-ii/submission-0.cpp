class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;
        for (auto num: nums)
            count[num]++;
        vector<int> result;
        for (auto &pair: count)
            if (pair.second> nums.size()/3)
                result.push_back(pair.first);
        return result;
    }
};