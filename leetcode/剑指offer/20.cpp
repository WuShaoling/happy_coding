#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cctype>

using namespace std;

class Solution {
   public:
    bool isNumber(string s) {
        if (s.empty()) return false;

        // 去首尾空格
        int begin = 0, end = s.size() - 1;
        while (begin < end && s[end] == ' ') end--;
        while (begin < end && s[begin] == ' ') begin++;
        s = s.substr(begin, end - begin + 1);
        if (s == " ") return false;

        // 判断非法字符
        int countSym = 0;    // 最多有 2 个，e 前面和 e 后面
        int countE = 0;      // 最多有 1 个
        int countPoint = 0;  // 最多有 1 个
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                continue;
            } else if (s[i] == '+' || s[i] == '-') {
                countSym++;
                if (countSym > 2) return false;
            } else if (s[i] == 'e' || s[i] == 'E') {
                countE++;
                if (countE > 1) return false;
                s[i] = tolower(s[i]);
            } else if (s[i] == '.') {
                countPoint++;
                if (countPoint > 1) return false;
            } else {
                return false;
            }
        }

        // 不能以 e 结尾
        if (s[s.size() - 1] == 'e') return false;

        int indexOfE = s.find('e');
        // 没有 e
        if (indexOfE == string::npos) return check0(s);

        // 有 e
        return check0(s.substr(0, indexOfE)) &&
               check1(s.substr(indexOfE + 1, s.size() - indexOfE));
    }

   private:
    bool check0(string str) {
        if (str.empty()) return false;

        // 去除 + - .
        int index = 0;
        if (str[0] == '+' || str[0] == '-' || str[0] == '.') index++;
        if (index == str.size()) return false;  // 去除  + - . 后没有字符了

        // 第二个字符是 .
        if (str[1] == '.') index++;
        if (index == str.size()) return false;

        // 剩下的进行判断
        for (; index < str.size(); index++) {
            if (str[index] != '.' && !isdigit(str[index])) return false;
        }
        return true;
    }

    bool check1(string str) {
        if (str.empty()) return false;

        // 不能出现点
        for (char c : str)
            if (c == '.') return false;

        // 去除 + - 号
        int index = 0;
        if (str[0] == '-' || str[0] == '+') index++;
        if (index == str.size()) return false;  // 去除 + - 号后没字符了

        // 剩下的进行判断
        for (; index < str.size(); index++) {
            if (!isdigit(str[index])) return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isNumber("0e0");
}