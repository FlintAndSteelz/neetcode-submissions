class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;
        for (auto num: nums){
            count[num]++;
            //add the quantity of each element
            if (count.size() > 2){
                //create new map to store a map 
                unordered_map<int,int> newCount;
                for (auto& entry: count)
                    if(entry.second >1)
                        newCount[entry.first] = entry.second-1;
                count = newCount;
                // recreate a new count;
            }
        }
        vector<int> result;
        for (auto& entry: count){
            int freq = 0;
            for (int num: nums)
                if (num == entry.first) freq ++;
            if (freq > nums.size()/3)
                result.push_back(entry.first);
        }
        return result;
    }
};