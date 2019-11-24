#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string> &words, string order) {
        for (int i = 0; i < order.length(); i++) {
            dic[order[i]] = i;
        }
        for (int i = 1; i < words.size(); i++) {
            if (!compare(words[i - 1], words[i])) {
                return false;
            }
        }
        return true;
    }

    bool compare(string &a, string &b) {
        int m = min(a.length(), b.length());
        for (int i = 0; i < m; i++) {
            if (dic[a[i]] < dic[b[i]]) {
                return true;
            } else if (dic[a[i]] > dic[b[i]]) {
                return false;
            } else {
                continue;
            }
        }
        return a.length() > b.length() ? false : true;
    }

private:
    int dic[256];
};

int main() {
    Solution solution;

    vector<string> str;
    str.push_back("hello");
    str.push_back("leetcode");

    cout << solution.isAlienSorted(str, "hlabcdefgijkmnopqrstuvwxyz") << endl;

    return 0;
}
