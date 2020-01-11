#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string addBinary(string a, string b) {
        if (a.size() == 0 && b.size() == 0) return "0";
        if (a.size() == 0) return b;
        if (b.size() == 0) return a;

        int i = a.size() - 1, j = b.size() - 1;
        int add = 0, t = 0;

        string res = "";
        for (; i >= 0 && j >= 0; i--, j--) {
            t = a[i] - '0' + b[j] - '0' + add;
            add = t / 2;
            res = to_string(t % 2) + res;
        }
        for (; i >= 0; i--) {
            t = a[i] - '0' + add;
            add = t / 2;
            res = to_string(t % 2) + res;
        }
        for (; j >= 0; j--) {
            t = b[j] - '0' + add;
            add = t / 2;
            res = to_string(t % 2) + res;
        }
        if (add != 0) res = "1" + res;
        return res;
    }
};

int main() {
    Solution s;
    cout << s.addBinary("1010", "1011");
}