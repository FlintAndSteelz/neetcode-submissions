class Solution {
private:

    void merge(vector<pair<int,int>> &arr, int left, int right,int mid){
        int i = left;
        int j = mid +1;
        vector<pair<int,int>> temp;
        while (i <= mid && j <= right){
            if (arr[i].first >= arr[j].first)
                temp.push_back(arr[i++]);
            else
                temp.push_back(arr[j++]);
        }
        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= right) temp.push_back(arr[j++]);
        //sau đó pass lại vào arr
        for (int k = left; k <= right;++k)
            arr[k] = temp[k-left];
    }

    void mergeSort(vector<pair<int,int>>&arr, int left, int right){
        if (left >= right) return;
        int mid = left + (right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, right, mid);
    }


public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> check;
        //đẩy vào hash map /count frequency
        for (int num: nums)
            check[num]++;
            //đẩy vào pair để sort
            // nhma lan nay thì đưa check.second lên trước để sort
        vector<pair<int,int>> arr;
        for (const auto&pairr: check)
            arr.push_back({pairr.second, pairr.first});
        mergeSort(arr, 0, arr.size()-1);
        //tạo vector result;
        vector<int> result;
        for (int i = 0; i < k;++i)
            result.push_back(arr[i].second);
        return result;
    }
};
