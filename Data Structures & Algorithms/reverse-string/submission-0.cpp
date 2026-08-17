class Solution {
private:
    void reverse(vector<char> &s, int left, int right){
        if (left > right)
            return;
        else{
            reverse(s, left+1, right-1);
            swap(s[left], s[right]);
        }
    }
public:
    void reverseString(vector<char>& s) {
        reverse(s, 0, s.size()-1);
    }
};