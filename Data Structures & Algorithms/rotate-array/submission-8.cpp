class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //instead of repeated shifting elements, we can directly compute the final position of each element
        // an element at index i, after rotation -> (i+k) % namespace

        int n = nums.size();
        vector<int> tempo(n);
        for (int i = 0;i < nums.size();++i)
            tempo[(i+k)%n] = nums[i];
        for (int i = 0; i < n;++i)
            nums[i] = tempo[i];

    }
};