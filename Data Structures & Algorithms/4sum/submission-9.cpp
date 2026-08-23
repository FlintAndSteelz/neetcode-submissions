class Solution {
    vector<vector<int>> result; // Lưu toàn bộ các bộ số thỏa mãn
    vector<int> quad;           // "Cái giỏ" lưu tạm thời các số đang xét
    
private:
    // HÀM 1: Thuật toán phân mảnh (Lomuto Partition) an toàn và ngắn gọn
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right]; 
        int i = left;
        for (int j = left; j < right; ++j) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }

    // HÀM 2: Thuật toán QuickSort
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int pivotPos = partition(nums, left, right);
        quickSort(nums, left, pivotPos - 1);
        quickSort(nums, pivotPos + 1, right);
    }

    // HÀM 3: Đệ quy K-Sum
    void kSum(vector<int>& nums, int k, int start, long long target) {
        int n = nums.size(); // Ép kiểu ngầm định về int để an toàn
        
        // TRƯỜNG HỢP CƠ SỞ: Khi k = 2, dùng Hai con trỏ
        if (k == 2) {
            int left = start;
            int right = n - 1;
            while (left < right) {
                long long sum = (long long) nums[left] + nums[right];
                if (sum < target) left++;
                else if (sum > target) right--;
                else {
                    quad.push_back(nums[left]);
                    quad.push_back(nums[right]);
                    result.push_back(quad);
                    quad.pop_back();
                    quad.pop_back();
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
            return;
        }
        
        // BƯỚC ĐỆ QUY: Khi k > 2
        for (int i = start; i < n - k + 1; ++i) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            quad.push_back(nums[i]);
            kSum(nums, k - 1, i + 1, target - nums[i]);
            quad.pop_back();
        }
    }

public:
    // HÀM GỌI CHÍNH
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) return {};
        quickSort(nums, 0, n - 1);
        kSum(nums, 4, 0, target);
        return result;
    }
};