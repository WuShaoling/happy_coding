#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        if (pushV.size() == 0) return true;

        stack<int> _s;
        int cur_index = 0;
        for (int i = 0; i < popV.size(); i++) {
            // 情况1，在栈顶，直接出栈
            if (!_s.empty() && _s.top() == popV[i]) {
                _s.pop();
                continue;
            }

            // 情况2，在剩下的序列里
            bool find = false;
            while (cur_index < pushV.size()) {
                // 如果找到了，cur_index直接后移，退出循环
                if (pushV[cur_index] == popV[i]) {
                    find = true;
                    cur_index++;
                    break;
                }
                // 如果没找到，将当前元素 push 到栈里
                _s.push(pushV[cur_index]);
                cur_index++;
            }

            // 在剩下的序列里找不到，说明不可能是
            if (!find) return false;
        }
        return true;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {1};
    vector<int> v2 = {2};

    cout << s.IsPopOrder(v1, v2);
}