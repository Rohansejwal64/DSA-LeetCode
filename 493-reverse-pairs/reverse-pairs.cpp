class Solution {
public:

int ans = 0;

void merge(vector<int>& arr, int low, int mid, int high) {
    // Count reverse pairs
    int j = mid + 1;
    for (int i = low; i <= mid; i++) {
        while (j <= high && (long long)arr[i] > 2LL * arr[j]) {
            j++;
        }
        ans += (j - (mid + 1));
    }

    // Standard merge procedure
    vector<int> temp;
    int left = low, right = mid + 1;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[right++]);
        }
    }

    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= high) temp.push_back(arr[right++]);

    for (int k = low; k <= high; ++k) {
        arr[k] = temp[k - low];
    }
}

void mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int reversePairs(vector<int>& nums) {
    ans = 0;
    mergeSort(nums, 0, nums.size() - 1);
    return ans;
}

};