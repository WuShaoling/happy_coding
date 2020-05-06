#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    bool checkIfCanBreak(string s1, string s2) {
        int n = s1.size();
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (s1[i] > s2[i]) {
                ok = false;
                break;
            }
        }
        if (ok) return true;

        ok = true;
        for (int i = 0; i < n; i++) {
            if (s1[i] < s2[i]) {
                ok = false;
                break;
            }
        }
        return ok;
    }
};

int main() {
    Solution s;
    cout << s.checkIfCanBreak("abc", "xya");
}