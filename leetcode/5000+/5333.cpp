#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
   public:
    int minSteps(string s, string t) {
        int ms[26] = {0};
        for (char c : s) ms[c - 'a']++;
        // for (int i = 0; i < 26; i++) {
        //     if (ms[i] != 0) cout << (char)('a' + i) << " " << ms[i] << endl;
        // }
        // cout << "---" << endl;

        int mt[26] = {0};
        for (char c : t) mt[c - 'a']++;
        // for (int i = 0; i < 26; i++) {
        //     if (mt[i] != 0) cout << (char)('a' + i) << " " << mt[i] << endl;
        // }

        int sum = 0;
        for (int i = 0; i < 26; i++) {
            if (ms[i] != 0 && mt[i] != 0) {
                // cout << (char)('a' + i) << " " << ms[i] << " " << mt[i] <<
                // endl;
                sum += min(ms[i], mt[i]);
            }
        }
        // cout << sum << endl;
        return s.size() - sum;
    }
};

int main() {
    Solution s;
    cout << s.minSteps("leetcode", "practice");
}