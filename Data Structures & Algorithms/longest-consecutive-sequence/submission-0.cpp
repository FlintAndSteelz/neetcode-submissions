class Solution {
public:
    int partition(vector<int> &nums, int left, int right){
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
    void quickSort(vector<int>& nums, int left, int right){
        if (left < right){
            int pivot = partition(nums, left, right);
            quickSort(nums, left, pivot-1);
            quickSort(nums, pivot+1, right);
        }
    }
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        int size= nums.size();
        quickSort(nums, 0, size-1);
        int streak = 1;
        int result = 1;
        for (int i = 1; i < size;i++){
            //duyệt từ phần tử thứ 2;
            //nếu số hiện tại khác số trước đó
            // thì bắt đầu xét không thì bỏ qua
            // nếu như lớn hơn một đơn vị thì cộng streak
            //Nếu khác thì lấy max của result với streak
            //sau đó reset lại streak
            if(nums[i] != nums[i-1]){
                if (nums[i] == nums[i-1]+1)
                    streak++;
                else
                    {
                        result = max(result, streak);
                        streak =1;
                    }
            }
            else
                continue;
        }
        return max(streak, result);
    }
};
