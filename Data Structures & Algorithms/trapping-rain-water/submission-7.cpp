class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        int n = height.size();
        int left = 0;
        int right = n -1;
        int leftMax = height[0];
        int rightMax = height[n-1];
        while (left < right){
            if (leftMax < rightMax){
                left++;
                leftMax = max(leftMax, height[left]);
                if (leftMax - height[left] > 0) result += leftMax - height[left];
            }
            else{
                right--;
                rightMax = max(rightMax, height[right]);
                if (rightMax - height[right] > 0)
                    result += rightMax - height[right];
            }
        }
        return result;
    }
};
