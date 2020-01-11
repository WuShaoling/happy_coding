#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m + n - 1, j = m - 1; j >= 0; i--, j--) {
            nums1[i] = nums1[j];
        }
        for (int i = 0; i < m + n; i++) {
            cout << nums1[i] << " ";
        }
        cout << endl;

        int cur = 0, i = n, j = 0;
        for (; i < m + n && j < n;) {
            if (nums1[i] < nums2[j]) {
                nums1[cur] = nums1[i];
                i++;
            } else {
                nums1[cur] = nums2[j];
                j++;
            }
            cur++;
        }
        while (i < m + n) {
            nums1[cur] = nums1[i];
            i++;
            cur++;
        }
        while (j < n) {
            nums1[cur] = nums2[j];
            j++;
            cur++;
        }
        // cout << i << " " << j << endl;
        // for (int i = 0; i < m + n; i++) {
        //     cout << nums1[i] << " ";
        // }
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    s.merge(nums1, 3, nums2, 3);
}