class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int left = 0;
        unordered_set<char> seen;
        for (int right = 0; right < s.size();right++){
            while (seen.find(s[right]) != seen.end()){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            result = max(result, right-left+1);
        }
        return result;
    }
};
