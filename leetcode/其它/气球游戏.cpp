#include <iostream>
#include <string>
#include <vector>

using namespace std;

int balloon(int m, int n, vector<int> nums) {
    vector<int> color_count(m + 1, 0);  //记录窗口内的颜色及出现次数
    int color = 0;  //记录窗口内不重复的颜色的个数
    int res = -1;

    int left = 0, right = 0;
    while (right < nums.size()) {
        // 当前颜色不为0，且未出现过，则当前窗口内的颜色数+1
        if (nums[right] != 0 && color_count[nums[right]] == 0) color++;

        color_count[nums[right]]++;

        // 找到了所有的颜色，尝试左指针往后移
        if (color == m) {
            while (left < n &&
                   (nums[left] == 0 || color_count[nums[left]] > 1)) {
                left++;
                color_count[nums[left]]--;
            }

            int cur_len = right - left + 1;
            if (res == -1 || cur_len < res) res = cur_len;
        }

        right++;
    }

    return res > n ? -1 : res;
}

int main() {
    vector<int> nums = {2, 5, 3, 1, 3, 2, 4, 1, 0, 5, 4, 3};
    cout << balloon(5, 12, nums);
}