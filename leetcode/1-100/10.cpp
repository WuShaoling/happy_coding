#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isMatch(string s, string p) { return matchCore(s, p, 0, 0); }

    bool matchCore(const string& s, const string& p, int ps, int pp) {
        if (ps == s.size() && pp == p.size()) return true;
        if (ps < s.size() && pp == p.size()) return false;

        if (pp + 1 < p.size() && p[pp + 1] == '*') {
            if (ps < s.size() && (s[ps] == p[pp] || p[pp] == '.')) {
                return matchCore(s, p, ps + 1, pp) ||
                       matchCore(s, p, ps, pp + 2);
            } else {
                return matchCore(s, p, ps, pp + 2);
            }
        } else {
            if (ps < s.size() && (s[ps] == p[pp] || p[pp] == '.')) {
                return matchCore(s, p, ps + 1, pp + 1);
            } else {
                return false;
            }
        }
    }

    bool matchCore2(const string& s, const string& p, int ps, int pp) {
        if (ps == s.size() && pp == p.size()) return true;
        if (ps < s.size() && pp == p.size()) return false;

        if (pp + 1 < p.size() && p[pp + 1] == '*') {
            if (ps < s.size() && (s[ps] == p[pp] || p[pp] == '.')) {
                return matchCore(s, p, ps + 1, pp) ||
                       matchCore(s, p, ps, pp + 2);
            } else {
                return matchCore(s, p, ps, pp + 2);
            }
        } else {
            if (ps < s.size() && (s[ps] == p[pp] || p[pp] == '.')) {
                return matchCore(s, p, ps + 1, pp + 1);
            } else {
                return false;
            }
        }
    }
};

int main() {}