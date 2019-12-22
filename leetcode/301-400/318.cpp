#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maxProduct(vector<string>& words) {
        int mm[words.size()];

        for (int i = 0; i < words.size(); i++) {
            mm[i] = bitMap(words[i]);
        }

        int res = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i; j < words.size(); j++) {
                if ((mm[i] & mm[j]) == 0) {
                    res = max(res, int(words[i].size() * words[j].size()));
                }
            }
        }
        return res;
    }

   private:
    int bitMap(string str) {
        int res = 0;
        for (char c : str) res |= 1 << (c - 'a');
        return res;
    }
};

int main() {
    Solution s;
    vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout << s.maxProduct(words);
}