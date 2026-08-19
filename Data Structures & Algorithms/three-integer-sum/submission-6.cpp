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
//our nums is ensured to have both negative and positive values
//sorted:
// skip all duplicated by moving the pointer
// ensure that moving the left or the right pointer will increase
//the sum in a predictable way
// so when we fix a value at first, it must be negative
//because nums[left] + nums[j] is negative too
//
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        mergeSort(nums, 0, nums.size()-1);

        for (int i = 0; i < nums.size();i++){
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int left = i +1;
            int right = nums.size()-1;
            while (left < right){
                if (-(nums[left] + nums[right]) == nums[i]){
                    result.push_back({nums[i], nums[left], nums[right]});           
                    left++;
                    right--;
                    // skipp duplicates are the left pointer
                    while (left < right && nums[left-1] == nums[left])
                        left++;
                }

                else if (-(nums[left] + nums[right]) < nums[i])
                    right--;
                else
                    left++;
            }
        }
        return result;
    }
};
