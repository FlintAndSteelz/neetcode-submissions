class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 1;
        for (int r = 1; r < nums.size();r++){
            if (nums[r] != nums[r-1]){
                nums[left++] = nums[r];
            }
        }
        return left;
    }
};