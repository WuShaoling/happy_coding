#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int nextGreaterElement(int n) {
        if (n < 10) return -1;
        string str = to_string(n);
        int len = str.size();

        // 158476531

        // 找到第一个升序位置
        int i = len - 2;
        while (i >= 0 && str[i] >= str[i + 1]) i--;
        if (i < 0) return -1;

        // 找到第一个大于 str[i] 的位置
        int j = len - 1;
        while (j >= 0 && str[i] >= str[j]) j--;
        swap(str[i], str[j]);

        for (int a = i + 1, b = len - 1; a < b; a++, b--) {
            swap(str[a], str[b]);
        }

        if (str.size() == 10 && str > to_string(INT_MAX)) return -1;

        return stoi(str);
    }
};

// 230241
// 230421
// 230412

int main() {
    Solution s;
    cout << s.nextGreaterElement(12443322);
}