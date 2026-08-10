class Solution {
public:

    int partition(vector<int>&nums, int left, int right){
        int pos = right;
        int pivot = nums[pos];
        right--;
        while (1){
            while (left <= right && nums[left] < pivot) left++;
            while (left <= right && nums[right] > pivot) right--;
            if (left < right){
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
            else
                break;
        }
        swap(nums[left], nums[pos]);
        return left;
    }

    void quickSort(vector<int>&nums, int left,int right){
        if (left < right){
            int pivot = partition(nums, left, right);
            quickSort(nums, left, pivot-1);
            quickSort(nums, pivot+1, right);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};