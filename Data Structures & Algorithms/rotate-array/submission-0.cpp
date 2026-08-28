class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int n = nums.size();
        //handle cases where K is larger than the array length
        while (k >0){
            int temp = nums[n-1];
            for (int i = n-1;i >0;i--)
                nums[i] = nums[i-1];
            nums[0] = temp;
            k--;
        }
    }
};