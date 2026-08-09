class Solution {
public:
    int partition(string &s, int left, int right){
        int pivotPos = right;
        int pivot = s[pivotPos];
        right--;
        while (1){
            while (left <= right && s[left] < pivot) left++;
            while (left <= right && s[right] > pivot) right--;
            if (left < right){
                swap(s[left], s[right]);
                left++;
                right--;
            }
            else
                break;
        }
        swap(s[left], s[pivotPos]);
        return left;
    }

    void quickSort(string &s, int left, int right){
        if (left < right){
            int pivot = partition(s, left, right);
            quickSort(s, left, pivot-1);
            quickSort(s, pivot+1, right);
        }

    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> check;
        for (const auto& value: strs){
            string key = value;
            quickSort(key, 0, key.length()-1);
            check[key].push_back(value);
        }
        vector<vector<string>> result;
        for (auto &pair :check)
            result.push_back(pair.second);
        return result;
    }
};
