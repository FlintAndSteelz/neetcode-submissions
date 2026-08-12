class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeros = 0;
        vector<int> result(nums.size(),0);
        int position;
        for (int i = 0; i < nums.size();++i){
            if (nums[i] ==0){
                zeros ++;
                position = i;
            }
        }

        if (zeros >=2)
            return result;
        
        else if (zeros == 1){
            int temp = 1;
            for (int i = 0; i < nums.size();++i)
                if (i != position)
                    temp = temp * nums[i];
            result[position] = temp;
            return result;
        }
        else{
            int product = 1;
            for (int i = 0; i < nums.size();++i)
                product = product * nums[i];
            for (int i = 0; i < nums.size();++i)
                result[i] = product / nums[i];
            return result;
        }



    }
};
