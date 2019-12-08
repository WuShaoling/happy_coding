#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    unsigned int doAtoi(string num) {
        unsigned int res = 0;
        for (int i = 0; i < num.size(); i++) {
            res = res * 10 + num[i] - '0';
        }
        return res;
    }

    int myAtoi(string str) {
        int index = 0;
        bool positive = true;

        // 去除空白符
        while (str[index] == ' ') index++;
        if (index == str.size()) return 0;

        // 第一个字符判断正负性
        if (str[index] == '-') {
            positive = false;
            index++;
        } else if (str[index] == '+') {
            index++;
        } else if (!isdigit(str[index])) {
            return 0;
        }

        // 去除前导0
        while (str[index] == '0') index++;
        if (index == str.size()) return 0;

        // 取连续数字串
        string num = "";
        for (; index < str.size(); index++) {
            if (!isdigit(str[index])) break;
            num += str[index];
        }
        if (num.size() == 0) return 0;

        // 最终结果
        if (num.size() > 10) {
            return positive ? 2147483647 : -2147483648;
        } else if (num.size() == 10) {
            if (positive)
                return num > "2147483647" ? 2147483647 : doAtoi(num);
            else
                return num > "2147483648" ? -2147483648 : -doAtoi(num);
        } else {
            return positive ? doAtoi(num) : -doAtoi(num);
        }
    }
};

int main() {
    Solution s;
    cout << s.myAtoi("2147483646");
}