class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*bởi vì chỉ có 3 element
        dùng mảng count đếm số lượng các màu
        sau đó xếp các số nhỏ nhất trước
        */
        vector<int> count(3);
        for (int &num: nums)
            count[num]++;
        int index = 0;
        for (int i = 0; i < 3;++i)
            while (count[i]-- >0)
                nums[index++] = i;
    }
};