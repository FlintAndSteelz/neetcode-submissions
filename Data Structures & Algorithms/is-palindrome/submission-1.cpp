class Solution {
public:
    bool alphaNum(char c){
        if (c>= 'A' && c <= 'Z'
        || c>= 'a' && c <='z'
        || c>='0' && c<= '9')
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        int left = 0, right = s.length()-1;
        while (left < right){
            while (alphaNum(s[left]) != true && left < right)
                left++;
            while (alphaNum(s[right]) != true && left < right)
                right--;
            if (tolower(s[left]) != tolower(s[right]))
                return false;
            left++, right--;
        }
        return true;
    }

};
