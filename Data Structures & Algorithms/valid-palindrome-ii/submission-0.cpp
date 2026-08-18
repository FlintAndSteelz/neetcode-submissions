class Solution {
private: 
    bool checkPalinI(const string& s){
        int left = 0, right = s.size()-1;
        while (left < right){
            if (s[left] != s[right])
                return false;
            left++, right--;
        }
        return true;
    }
public:

    bool validPalindrome(string s) {
        if (checkPalinI(s))
            return true;
        for (int i = 0; i < s.length();++i){
            string newString = s.substr(0,i) + s.substr(i+1);
            if (checkPalinI(newString))
                return true;
        }
        return false;
    }
};