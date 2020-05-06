#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int longestSubstring(string s, int k) {
        return myCount(s, k, 0, s.size() - 1);
    }

    int myCount(string& s, int k, int left, int right) {
        unordered_map<char, int> mm;
        for (int i = left; i <= right; i++) mm[s[i]]++;

        int ll = left, rr = right;
        while (ll <= rr && mm[s[ll]] < k) ll++;
        while (ll <= rr && mm[s[rr]] < k) rr--;
        if (rr - ll + 1 < k) return 0;

        int part = ll;
        while (part <= rr && mm[s[part]] >= k) part++;
        if (part >= rr) return rr - ll + 1;

        return max(myCount(s, k, ll, part - 1), myCount(s, k, part + 1, rr));
    }
};

int main() {}