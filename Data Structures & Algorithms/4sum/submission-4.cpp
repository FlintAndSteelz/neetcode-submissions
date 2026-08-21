class Solution {
private:
    int partition(vector<int>&nums, int left,int right){
        int pos = right;
        int pivot = nums[pos];
        right--;
        while (true){
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
    void quickSort(vector<int>&nums, int left, int right){
        if (left >= right) return;
        int pivotPos = partition(nums, left, right);
        quickSort(nums,left, pivotPos-1);
        quickSort(nums, pivotPos+1, right);
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        quickSort(nums, 0, n-1);
        unordered_map<int,int> count;
        vector<vector<int>> result;
        for (auto num: nums)
            count[num]++;
        for (int i = 0; i < n;++i){
            count[nums[i]]--;
            if (i > 0 && nums[i] ==  nums[i-1]) continue;
            for (int j = i+1; j < n;++j ){
                count[nums[j]]--;
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                for (int k = j +1; k < n;++k){
                    count[nums[k]]--;
                    if (k > j +1 && nums[k] == nums[k-1]) continue;
                    
                    long long fourth = target - (nums[i] + nums[j] + 0LL + nums[k]);
                    if (fourth < INT_MIN || fourth > INT_MAX) continue;
                    if (count[fourth] >0)
                        result.push_back({nums[i], nums[j], nums[k], int(fourth)});

                }
                for (int k = j+1; k < nums.size();k++)
                    count[nums[k]]++;
            }
            for (int j = i+1; j < nums.size();j++)
                count[nums[j]]++;
        }
        return result;
    }
};