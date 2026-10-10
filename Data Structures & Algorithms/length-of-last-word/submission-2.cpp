class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0, i =0;
        while (i < s.length()){
            if (s[i] == ' '){
                while ( i < s.length() && s[i] == ' ')
                    i++;
                if (i == s.length())
                    return len;
                len = 0;
            }
            else{
                len++;
                i++;
            }
        }
        return len;
    }
};