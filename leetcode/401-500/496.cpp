#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        map<int, int> mm;
        for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty() && nums2[i] > nums2[st.top()]) {
                mm[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }

        vector<int> ans(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++) {
            if (mm.find(nums1[i]) != mm.end()) {
                ans[i] = mm[nums1[i]];
            }
        }
        return ans;
    }
};

/*
4 1 2
1 3 4 2

1 3

2 4
1 2 3 4

4 1
*/

int main() {
    Solution s;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> ans = s.nextGreaterElement(nums1, nums2);
    for (int i : ans) cout << i << "  ";
    cout << endl;
}