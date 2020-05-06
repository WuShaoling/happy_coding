#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // int oldn = nums.size();

        // vector<int> temp(oldn * 2);
        // for (int i = 0; i < nums.size(); i++) {
        //     temp[i] = temp[i + oldn] = nums[i];
        // }

        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] > nums[st.top()]) {
                ans[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] > nums[st.top()]) {
                ans[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }

        // for (int i : nums) cout << i << " ";
        // cout << endl;
        // for (int i : ans) cout << i << " ";
        // cout << endl;

        // for (int i = 0; i < n; i++) {
        //     if (ans[i] == -1) {
        //         ans[i] = ans[i + oldn];
        //     }
        // }
        // ans.resize(n);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 4, 3, 2, 1};
    vector<int> ans = s.nextGreaterElements(nums);
    for (int i : ans) cout << i << " ";
}