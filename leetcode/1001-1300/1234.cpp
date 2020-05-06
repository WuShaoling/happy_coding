#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int balancedString(string s) {
        int n = s.size();
        int avg = n / 4;

        // 'Q', 'W', 'E', 'R'
        unordered_map<char, int> count = {
            {'Q', 0}, {'W', 0}, {'E', 0}, {'R', 0}};
        for (int i = 0; i < s.size(); i++) {
            count[s[i]]++;
        }

        int i = 0, j = 0;
        int ans = s.size() - 1;
        while (j < n) {
            count[s[j]]--;
            while (i <= j && count['Q'] <= avg && count['W'] <= avg &&
                   count['E'] <= avg && count['R'] <= avg) {
                ans = min(ans, j - i + 1);

                // 收缩左边界
                count[s[i]]++;
                i++;
            }
            j++;
        }
        return i == j ? 0 : ans;
    }
};

int main() {
    Solution s;
    s.balancedString("QQWE");
}