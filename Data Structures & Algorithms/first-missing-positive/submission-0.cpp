class Solution {
public:
    void merge(vector<int>& arr, int left, int right, int mid){
        vector<int> temp;
        int i = left;
        int j = mid +1;
        while (i <= mid && j <= right){
            if (arr[i] <= arr[j])
                temp.push_back(arr[i++]);
            else
                temp.push_back(arr[j++]);
        }
        while ( i <= mid) temp.push_back(arr[i++]);
        while (j <= right) temp.push_back(arr[j++]);
        for (int k = left; k <= right;++k)
            arr[k] = temp[k-left];
    }
    void mergeSort(vector<int>& nums, int left, int right){
        if (left >= right) return;
        int mid = left + (right-left)/2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, right, mid);
    }

    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        mergeSort(nums, 0 , size-1);
        int missing = 1;
        for (auto num: nums)
            if (num > 0 && num == missing) 
                missing++;
        return missing;
    }
};