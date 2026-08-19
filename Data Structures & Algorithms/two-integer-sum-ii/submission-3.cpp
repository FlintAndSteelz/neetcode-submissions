class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size();++i){
            int tempo = target - numbers[i];
            int left = i+1, right = numbers.size()-1;
            while (left <= right){
                int mid = left + (right-left)/2;
                if (numbers[mid] == tempo)
                    return {i+1, mid+1};
                else if (numbers[mid] > tempo)
                    right = mid-1;
                else
                    left = mid +1;
            }
        }
        return {};
    }
};
