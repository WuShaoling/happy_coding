#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    bool patternMatching(string pattern, string value) {
        // 1. 如果都为空，返回 true
        if (pattern == "" && value == "") return true;

        // 2. 如果 pattern 为空，返回 false
        if (pattern == "") return false;

        // 计算 pattern 中 a 和 b 的个数
        int countA = 0;
        int countB = 0;
        for (char c : pattern) {
            if (c == 'a')
                countA++;
            else
                countB++;
        }
        // 3. 如果 value 为空
        if (value == "") {
            // 3.1 a 或 b 的个数为0，返回 true，个数非 0 的匹配 ""
            if (countA == 0 || countB == 0) return true;
            // 3.2 a b 都不为 0，直接返回 false
            return false;
        }

        // 至此，pattern 和 value 非空，且 countA countB 不同时为0
        if (countA == 0) {  // 4. 如果 a 的个数为 0，检查 b 是否匹配
            if (value.size() < countB || value.size() % countB != 0)
                return false;
            int n = value.size() / countB;  // a 匹配的长度
            for (int i = n; i < value.size(); i++) {
                if (value[i] != value[i - n]) return false;
            }
            return true;
        }
        if (countB == 0) {  // 5. 如果 a 的个数为 0，检查 b 是否匹配
            if (value.size() < countA || value.size() % countA != 0)
                return false;
            int n = value.size() / countA;  // a 匹配的长度
            for (int i = n; i < value.size(); i++) {
                if (value[i] != value[i - n]) return false;
            }
            return true;
        }

        // pattern value 都不为空，a，b 都不为 0
        // a 的长度最多为 value.size() / countA
        for (int lenA = 0; lenA <= value.size() / countA; lenA++) {
            // b字符串的长度不是整数，continue
            int left = value.size() - lenA * countA;
            if (left % countB != 0) continue;

            int lenB = left / countB;
            string a = "", b = "";
            if (lenA == 0) {
                b = value.substr(0, lenB);
            } else if (lenB == 0) {
                a = value.substr(0, lenA);
            } else {
                a = value.substr(pattern.find_first_of('a') * lenB, lenA);
                b = value.substr(pattern.find_first_of('b') * lenA, lenB);
            }

            int begin = 0;
            bool match = true;
            for (char c : pattern) {
                if (c == 'a') {
                    if (value.substr(begin, lenA) != a) {
                        match = false;
                        break;
                    }
                    begin += lenA;
                } else {
                    if (value.substr(begin, lenB) != b) {
                        match = false;
                        break;
                    }
                    begin += lenB;
                }
            }
            if (match) return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.patternMatching("abba", "dogcatcatdog");
}