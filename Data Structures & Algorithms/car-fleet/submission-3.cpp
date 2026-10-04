class Solution {
private:
    void merge(vector<pair<int,int>>& arr, int left, int right, int mid) {
        vector<pair<int,int>> temp;
        int i = left;
        int j = mid + 1;
        while (i <= mid && j <= right) {
            if (arr[i].first >= arr[j].first)
                temp.push_back(arr[i++]);
            else
                temp.push_back(arr[j++]);
        }

        while (i <= mid)
            temp.push_back(arr[i++]);

        while (j <= right)
            temp.push_back(arr[j++]);

        for (int k = left; k <= right; ++k)
            arr[k] = temp[k - left];
    }

    void mergeSort(vector<pair<int,int>>& arr, int left, int right) {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, right, mid);
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> posAndSpeed;
        for (int i = 0; i < n;++i)
            posAndSpeed.push_back({position[i], speed[i]});
        mergeSort(posAndSpeed, 0, n-1);

        vector<double> stk;
        for (auto &pairr: posAndSpeed){
            double time = (double)(target - pairr.first)/ pairr.second;
            stk.push_back(time);
            if (stk.size()>=2 && stk.back() <= stk[stk.size()-2])
                stk.pop_back();
        }
        return stk.size();

    }
};
