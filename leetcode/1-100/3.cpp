#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int arr[256];
        memset(arr, -1, 256 * sizeof(int));
        int max_len = -1;
        int cur = 0;

        for (int i = 0; i < s.size(); i++) {
            int index = s[i];
            if (arr[index] == -1) {
                arr[index] = i;
                cur++;
            } else {
                if (cur > max_len) {
                    max_len = cur;
                }

                int pos = arr[index];
                // 重复的元素 前面的清空
                for (int j = 0; j < pos; j++) {
                    arr[s[j]] = -1;
                }
                // 重复的元素 后面的到当前设置位置
                for (int j = pos + 1; j <= i; j++) {
                    arr[s[j]] = j;
                }
                cur = i - pos;
            }
        }
        if (cur > max_len) return cur;
        return max_len;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("bprkpqlbtqpqphr") << endl;
}