#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int numSteps(string s) {
        vector<char> str(s.size(), '0');
        int i = s.size() - 1;
        for (char c : s) {
            s[i--] = c;
        }
        int left = 0, right = s.size() - 1;
        while (str[right] == '0') {
            right--;
        }
        while (true) {
        }

        // 0123456789
        // 1010110101
        // char str[s.size() * 2];
        // memset(str, '0', s.size() * 2);
        // memcpy(str + s.size(), s.c_str(), s.size());

        // // printf("%s", str);

        // int left = s.size();
        // int right = s.size() * 2 - 1;
        // while (str[left] == '0') left++;

        // int ans = 0;
        // while (true) {
        //     if (left == right && str[left] == '1') {
        //         break;
        //     }
        //     if (str[right] == '0') {  // 偶数，右移
        //         right--;
        //     } else {  // 奇数+1
        //     }
        //     ans++;
        // }

        return 0;
    }
};

int main() {
    Solution s;
    s.numSteps("abcde");
}