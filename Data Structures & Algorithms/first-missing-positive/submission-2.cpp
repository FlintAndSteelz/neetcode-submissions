class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n,false);
        for (auto & num: nums)
            if (num >= 1 && num <= n) seen[num-1] = true;
        for (int i = 0; i < n;++i)
            if (seen[i] == false)
                return i +1;
        return n+1;
    }
};