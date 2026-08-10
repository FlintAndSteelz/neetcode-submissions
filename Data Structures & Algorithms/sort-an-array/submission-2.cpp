class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
private:
    void mergeSort(vector<int>& arr, int left, int right){
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, right, mid);
    }
    void merge(vector<int> &arr, int left, int right, int mid){
        vector<int> temp;
        int i = left;
        int j = mid+1;
        //two pointers
        //trường hợp mà size của arr là chẵn
        //nếu mà lẻ thì sẽ phải push_back các element còn lại
        while (i <= mid && j <= right){
            if (arr[i] <= arr[j]){
                temp.push_back(arr[i++]);
            } // ĐÃ SỬA: Thêm dấu đóng ngoặc nhọn bị thiếu ở đây
            else
                temp.push_back(arr[j++]);
        }
        
        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= right) temp.push_back(arr[j++]); // ĐÃ SỬA: Đổi j+1 thành j++
        for (int k = left; k <= right;k++)
            arr[k] = temp[k-left];

    }
};