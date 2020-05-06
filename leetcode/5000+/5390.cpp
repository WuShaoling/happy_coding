#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char, int> index = {
            {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}};

        int ans = 0;
        int count[5] = {0};
        for (char c : croakOfFrogs) {
            // 排除掉其它字符
            if (c != 'c' && c != 'r' && c != 'o' && c != 'a' && c != 'k')
                return -1;

            if (c == 'c') {
                count[0]++;  // 新增加一个青蛙
            } else {
                int cur_idx = index[c];

                // 所依赖的前一个字符不存在，直接返回-1
                if (count[cur_idx - 1] == 0) return -1;

                // 前一个字符 -1
                count[cur_idx - 1]--;

                // 如果不是结尾字符，当前字符数量 +1
                if (c != 'k') count[cur_idx]++;
            }
            ans = max(ans, count[0] + count[1] + count[2] + count[3]);
        }
        if (count[0] || count[1] || count[2] || count[3]) return -1;
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.minNumberOfFrogs("crcoakroak") << endl;
}