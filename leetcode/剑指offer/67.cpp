#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

class Solution {
   public:
    int strToInt(string str) {
        int index = 0;
        while (index < str.size() && str[index] == ' ') index++;
        if (index >= str.size()) return 0;

        // 判断首字符
        if (!isdigit(str[index]) && str[index] != '+' && str[index] != '-') {
            return 0;
        }

        // 取符号
        bool positive = true;
        if (str[index] == '-') {
            index++;
            positive = false;
        } else if (str[index] == '+') {
            index++;
        }

        // 取数字
        int end = index;
        while (end < str.size() && isdigit(str[end])) end++;
        if (end - index == 0) return 0;
        str = str.substr(index, end - index);

        // 去除前导0
        index = 0, end = str.size();
        while (index < end && str[index] == '0') index++;
        if (index == end) return 0;
        str = str.substr(index, end - index);

        if (str.size() > 10) {
            return positive ? INT_MAX : INT_MIN;
        } else if (str.size() == 10) {
            if (positive && str >= "2147483647") return INT_MAX;
            if (!positive && str >= "2147483648") return INT_MIN;
        }

        int res = 0;
        for (char c : str) {
            res = res * 10 + (c - '0');
        }
        return positive ? res : -res;
    }
};

int main() {
    Solution s;
    cout << s.strToInt("   -42");
}