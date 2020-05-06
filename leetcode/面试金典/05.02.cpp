#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    string printBin(double num) {
        if (num >= 1 || num < 0) return "ERROR";
        string res = "0.";
        while (num != 0) {
            num = num * 2;
            res += to_string((int)num);
            if (num >= 1) num -= 1;
            if (res.size() == 32 && num != 0.0) return "ERROR";
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.printBin(-0.5);
}