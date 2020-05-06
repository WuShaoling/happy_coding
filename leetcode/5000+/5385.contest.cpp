#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    int maxDiff(int num) {
        string str = to_string(num);
        int len = str.size();

        string max1 = str;
        string min1 = str;

        for (int x = '0'; x <= '9'; x++) {
            for (int y = '0'; y <= '9'; y++) {
                if (x == y) continue;
                string temp = str;
                for (int i = 0; i < len; i++) {
                    if (temp[i] == x) {
                        temp[i] = y;
                    }
                }
                if (check(temp)) {
                    if (temp > max1) max1 = temp;
                    if (temp < min1) min1 = temp;
                }
            }
        }
        return stoi(max1) - stoi(min1);
    }

    bool check(string& str) {
        if (str[0] == '0') return false;
        for (char c : str)
            if (c != '0') return true;
        return false;
    }
};

int main() {
    Solution s;
    cout << s.maxDiff(1e8);
}