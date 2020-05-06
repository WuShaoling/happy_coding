#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<int> mm(n, -1);
        return helper(s, k, mm, 0);
    }

    int helper(string& s, int k, vector<int>& mm, int idx) {
        if (idx == s.size()) return 1;
        if (s[idx] == '0') return 0;
        if (mm[idx] != -1) return mm[idx];

        long ans = 0;
        long sum = 0;
        for (int i = idx; i < s.size(); i++) {
            sum = sum * 10 + s[idx] - '0';
            if (sum > k) break;
            ans += helper(s, k, mm, idx + 1);
            ans %= 1000000007;
        }
        return mm[idx] = ans;
    }
};

int main() {}