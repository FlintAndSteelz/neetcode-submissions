class Solution {
public:
/*
elements appearing more than n/3 is rare
there can be at most two such elements
so for each unique element we count its occurences and check 
if it exceeds n/3/ 

*/
    vector<int> majorityElement(vector<int>& nums) {
        unordered_set<int> result;
        for (auto num: nums){
            int count = 0;
            for (int i = 0; i < nums.size();++i)
                if (nums[i] == num) count ++;
            if (count > nums.size()/3) result.insert(num);
        }
        return vector<int>(result.begin(), result.end());
    }
};