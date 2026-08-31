class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return  0;
        stack<int> container;
        int result = 0;
        for (int i= 0; i < height.size();++i){
            while (container.empty()==false && height[i] >= height[container.top()]){
                int mid = height[container.top()];
                container.pop();
                if (container.empty() == false){
                    int right = height[i];
                    int left = height[container.top()];
                    int heightt = min(left, right) - mid;
                    int width = i - container.top() - 1;
                    result += heightt * width;
                }
            }
            container.push(i);

        }
        return result;
    }
};
