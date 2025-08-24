class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int s1 = nums1.size(), s2 = nums2.size();
    int n = s1 + s2;

    int ind1 = (n % 2 == 0) ? (n / 2) - 1 : -1; // only needed if even
    int ind2 = n / 2;

    int ind1e = -1, ind2e = -1;
    int i = 0, j = 0, count = 0;

    while (i < s1 || j < s2) {
        int val;
        if (j >= s2 || (i < s1 && nums1[i] <= nums2[j])) {
            val = nums1[i++];
        } else {
            val = nums2[j++];
        }

        if (count == ind1) ind1e = val;
        if (count == ind2) {
            ind2e = val;
            break; // no need to continue
        }
        count++;
    }

    if (n % 2 == 0)
        return (ind1e + ind2e) / 2.0;
    else
        return ind2e;
}
};