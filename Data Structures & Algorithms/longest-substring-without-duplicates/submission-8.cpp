class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> position;
        int left =0;
        int result = 0;
        for (int right = 0; right < s.length();++right){
            if (position.find(s[right]) != position.end())
                left = max(position[s[right]]+1, left);
            position[s[right]] = right;
            result = max(result, right-left+1);
        }
        return result;
    }
};
