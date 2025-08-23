class Solution {
public:
    bool check(vector<int>& arr, int &m, int &k, int &mid) {
        int flowers = 0;
        int bouquets = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= mid) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }

        return bouquets >= m;
    }
    int minDays(vector<int>& arr, int m, int k) {
        int maxi = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            maxi = max(maxi, arr[i]);
        }
        int s = 1;
        int e = maxi;
        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (check(arr, m, k, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};