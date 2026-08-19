class Solution {
private:
    void merge(vector<int>&nums, int left, int right, int mid){
        vector<int> tempo;
        int i = left;
        int j = mid +1;
        while (i <= mid && j  <= right){
            if (nums[i] < nums[j])
                tempo.push_back(nums[i++]);
            else
                tempo.push_back(nums[j++]);
        }
        while (i <= mid) tempo.push_back(nums[i++]);
        while (j <= right) tempo.push_back(nums[j++]);
        for (int k = left; k <= right;++k)
            nums[k] = tempo[k-left];
    }
    void mergeSort(vector<int>& nums, int left, int right){
        if (left >= right) return;
        int mid = left + (right-left)/2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, right, mid);
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> mapp;
        vector<vector<int>> result;
        mergeSort(nums,0, nums.size()-1);
        for (auto num: nums)
            mapp[num]++;
        for (int i = 0; i < nums.size();++i){
            mapp[nums[i]] --;
            //decrease the count of nums[i], so it won't be used again
            if ( i > 0 && nums[i] == nums[i-1]) continue;
            //skip the duplicates
            for (int j = i + 1; j < nums.size();++j){
                mapp[nums[j]] --;
                //ecrease the count of nums[j], so it won't be used again
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                int target = -(nums[i]+ nums[j]);
                if (mapp[target] > 0)
                    result.push_back({nums[i], nums[j], target});
            }
            for (int k = i +1; k < nums.size();k++)
                mapp[nums[k]] ++;
        }

        return result;
    }
};







