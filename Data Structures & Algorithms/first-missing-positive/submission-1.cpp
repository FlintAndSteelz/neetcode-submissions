class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int missing = 1;
        while (true){
            bool flag = true;
            //giả sử là không tìm thấy missing;
            for (auto & num: nums){
                if (num == missing){
                    flag = false;
                    break;
                }
            }
            if (flag) return missing;
            else missing ++;
        }
    }
};