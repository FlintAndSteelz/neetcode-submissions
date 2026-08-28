class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return; 
        
        k = k % n; // Correct modulo operation
        k = n - k;
        while (k > 0) {
            int temp = nums[0];
            for (int i = 1; i < n; ++i) {
                nums[i-1] = nums[i];
            }
            nums[n-1] = temp;
            k--;
        }
    }
};