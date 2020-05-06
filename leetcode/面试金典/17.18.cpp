#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        if (big.size() == 0) return {};

        unordered_map<int, int> m_small;
        for (int i : small) m_small[i]++;

        unordered_map<int, int> m_big;
        int cur_count = 0, target_count = m_small.size();
        int ans_left = 0, ans_right = 0, ans_len = INT_MAX;
        int right = 0, left = 0;
        while (right < big.size()) {
            int num = big[right];

            m_big[num]++;
            if (m_big[num] == m_small[num]) cur_count++;

            // 尝试收缩左边界
            while (cur_count == target_count) {
                // 更新结果
                if (right - left + 1 < ans_len) {
                    ans_left = left;
                    ans_right = right;
                    ans_len = right - left + 1;
                }

                num = big[left];
                if (m_big[num] == m_small[num]) cur_count--;
                m_big[num]--;
                left++;
            }

            right++;
        }
        if (ans_len == INT_MAX) return {};
        return {ans_left, ans_right};
    }
};

int main() {
    Solution s;
    vector<int> big = {1};
    vector<int> small = {1, 2};
    vector<int> ans = s.shortestSeq(big, small);
    for (int i : ans) cout << i << " ";
}