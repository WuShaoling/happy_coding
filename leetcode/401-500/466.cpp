#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        // 判断能不能从s1获得s2
        if (!checkCanFromS1ToS2(s1, s2)) return 0;

        // 找到能从s1获得s2的情况下，s1最小重复次数
        int repeat = 0;
        for (int i = 0; i < s2.size();) {
            int j = 0;
            while (i < s2.size() && j < s1.size()) {
                if (s2[i] == s1[j]) {
                    i++;
                    j++;
                } else {
                    j++;
                }
            }
            repeat++;
        }

        // s1 需要重复 repeat 次才能得到 s2
        // s2 重复 n2 次，s1 需要重复 repeat * n2 次
        int s1NeedRepeat = repeat * n2;
        if (s1NeedRepeat > n1) return 0;
        return n1 / s1NeedRepeat;
        // s1 重复 10 次 得到 s2
        // s2 重复 2 次，s1 需要重复 20 次

        // return repeat;
    }

   private:
    bool checkCanFromS1ToS2(string& s1, string& s2) {
        // 如果s2中存在某个字符，这个字符在s1中不存在，则s2无法从s1获得
        int flag1[128] = {0};
        int flag2[128] = {0};
        for (char c : s1) flag1[c]++;
        for (char c : s2) flag2[c]++;
        for (int i = 0; i < 128; i++) {
            if (flag2[i] != 0 && flag1[i] == 0) {
                return false;
            }
        }
        return true;
    }
};

/*
"aaaaaaaaa"
"aa"
3
"aa"
1
*/

int main() {
    Solution s;
    cout << s.getMaxRepetitions("aaa", 3, "aa", 1);
}
