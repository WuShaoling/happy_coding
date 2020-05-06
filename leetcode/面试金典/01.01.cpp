#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    bool isUnique(string astr) {
        long long int a = 0, b = 0, t;
        for (char c : astr) {
            t = 1;
            if (c < 64) {
                t <<= c;
                if ((a & t) == t) return false;
                a |= t;
            } else {
                t <<= (c - 64);
                // cout << b << " " << t << " ";
                if ((b & t) == t) return false;
                b |= t;
                // cout << b << endl;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isUnique("abc");
}