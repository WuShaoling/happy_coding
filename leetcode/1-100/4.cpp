#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int left = (n + m + 1) / 2;
        int right = (n + m + 2) / 2;
        return (getK(nums1, 0, n - 1, nums2, 0, m - 1, left) +
                getK(nums1, 0, n - 1, nums2, 0, m - 1, right)) *
               0.5;
    }

    int getK(vector<int>& nums1, int s1, int e1, vector<int>& nums2, int s2,
             int e2, int k) {
        int len1 = e1 - s1 + 1;
        int len2 = s2 - s2 + 1;
        if (len2 < len1) return getK(nums2, s2, e2, nums1, s1, e1, k);

        if (len1 == 0) return nums2[s2 + k - 1];
        if (k == 1) return min(nums1[s1], nums2[s2]);

        int i = s1 + min(len1, k / 2) + 1;
        int j = s2 + min(len2, k / 2) + 1;
        if (nums1[i] > nums2[j]) {
            return getK(nums1, s1, e1, nums2, j + 1, e2, k - (j - s2 + 1));
        } else {
            return getK(nums1, i + 1, e1, nums2, s1, e2, k - (i - s1 + 1));
        }
    }
};

int main() {
    vector<int> v1 = {1, 2, 3, 4};
    vector<int> v2 = {5, 6};
    Solution s;
    cout << s.findMedianSortedArrays(v1, v2);
}