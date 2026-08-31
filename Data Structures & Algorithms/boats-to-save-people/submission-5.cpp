class Solution {
private:
    void merge(vector<int> &arr, int left, int right, int mid){
        vector<int> temp;
        int i = left;
        int j = mid +1;
        while (i <= mid && j <= right){
            if (arr[i] <= arr[j]) 
                temp.push_back(arr[i++]);
            else
                temp.push_back(arr[j++]);
        }
        //push back các elements còn thừa khi size bị lẻ
        while (i <= mid) temp.push_back(arr[i++]);
        while (j<= right) temp.push_back(arr[j++]);
        for (int k = left; k <= right;++k)
            arr[k] = temp[k -left];
    }

    void mergeSort(vector<int> &arr, int left, int right){
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        //chia arr thành các individual element
        mergeSort(arr, left, mid);
        mergeSort(arr,mid+1, right);
        //bây giờ thì merge từng individual lại 1 + 1 = 2 -> 2+2 = 4;
        merge(arr, left, right, mid);
    }
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        mergeSort(people,0, n-1);
        int left = 0;
        int right =n -1;
        int boats = 0;
        while (left <= right){
            int remain = limit - people[right];
            right--;
            boats++;
            if (left <= right && people[left] <= remain) left++;
        }
        return boats;
    }
};