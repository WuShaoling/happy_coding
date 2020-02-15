#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    bool isUnique(string astr) {
        cout << astr << endl;
        long long int a = 0, b = 0, t;
        for (char c : astr) {
            cout << b << " ";
            t = 1;
            if (c < 64) {
                cout << c << "-" << endl;
                t <<= c;
                if ((a & t) == 1) return false;
                a |= t;
            } else {
                // t <<= (c - 64);
                // cout << c << " " << (int)c << " " << t << endl;
                if ((b & t) == 1) return false;
                b |= t;
            }
            cout << b << endl;
        }
        return true;
    }
};
int main() {
    Solution s;
    cout << s.isUnique("leetcode");
}