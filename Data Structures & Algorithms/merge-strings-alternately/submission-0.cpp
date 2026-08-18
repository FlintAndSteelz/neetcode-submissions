class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int start1 = 0, start2 = 0;
        string result = "";
        while (start1 < word1.size() || start2 < word2.size()){
            if (start1 < word1.size()) result += word1[start1++];
            if (start2 < word2.size()) result += word2[start2++];
        }
        return result;
    }
};