#include <algorithm>
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        vector<int> leftMin = getLeftMin(heights);
        vector<int> rightMin = getRightMin(heights);

        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            int w = 0;
            int left = leftMin[i] + 1;
            int right = rightMin[i] - 1;
            res = max(res, heights[i] * (right - left + 1));
        }

        return res;
    }

    // 获取右侧第一个小于当前值的位置
    vector<int> getRightMin(vector<int>& heights) {
        vector<int> res(heights.size(), heights.size());
        stack<int> st;
        for (int i = 0; i < heights.size(); i++) {
            // 栈内是单调递增顶
            // 如果当前值小于栈顶，说明当前值是栈内元素的右边小值
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int t = st.top();
                st.pop();
                res[t] = i;
            }
            st.push(i);
        }
        return res;
    }

    // 获取左侧第一个小于当前值的位置
    vector<int> getLeftMin(vector<int>& heights) {
        vector<int> res(heights.size(), -1);
        stack<int> st;
        for (int i = 0; i < heights.size(); i++) {
            // 保证栈顶是小于当前元素的值
            while (!st.empty() && heights[i] <= heights[st.top()]) st.pop();
            if (!st.empty()) res[i] = st.top();
            st.push(i);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> v = {2, 1, 5, 6, 2, 3};
    cout << s.largestRectangleArea(v);
}

/*
0 1 2 3 4
1 2 5 0 6


5
2
1
*/