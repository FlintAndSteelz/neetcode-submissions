class Solution {
public:
    int maxArea(vector<int>& heights) {
        //we must move the pointer at the shorter line inward
        // moving the taller line never helps because it keeps thr height same
        //but reduces the width by always moving the shorter line, we explore all meaningful possibilities
        int left = 0;
        int right = heights.size()-1;
        int result = 0;
        while (left < right){
            int area = (right-left) * min(heights[left], heights[right]);
            if (area > result)
                result = area;
            if (heights[right] >= heights[left])
                left++;
            else if (heights[left] > heights[right])
                right--;
            
        }
        return result;
    }
};
