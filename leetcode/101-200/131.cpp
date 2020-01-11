#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<string>> partition(string s) {
        helper(s, 0);
        return res;
    }

   private:
    void helper(string& s, int start) {
        if (start == s.size()) {
            res.push_back(cur);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (!judge(s, start, i)) continue;
            cur.push_back(s.substr(start, i - start + 1));
            helper(s, i + 1);
            cur.pop_back();
        }
    }

    bool judge(string& s, int begin, int end) {
        for (; begin < end; begin++, end--) {
            if (s[begin] != s[end]) return false;
        }
        return true;
    }

    vector<string> cur;
    vector<vector<string>> res;
};

int main() {
    Solution s;
    vector<vector<string>> res = s.partition("aaaa");
    for (vector<string> v : res) {
        for (string s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
}