class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for (int num: nums)
            count[num]++;
        vector<vector<int>> frequency(nums.size()+1);
        for (const auto& key: count)
            frequency[key.second].push_back(key.first);
        vector<int> result;
        for (int i = frequency.size()-1;i>=0;--i){
            for (int num: frequency[i])
                result.push_back(num);
                if (result.size() == k)
                    return result;
        }

        return result;
    }
};
