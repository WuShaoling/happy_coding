#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;

        map<string, int> mm;
        for (int i = 0; i < words.size(); i++) {
            if (mm.find(words[i]) == mm.end()) {
                mm[words[i]] = 1;
            } else {
                mm[words[i]]++;
            }
        }

        int size = words.size() + 5;
        set<string> sort[size];
        map<string, int>::iterator it = mm.begin();
        for (; it != mm.end(); it++) {
            sort[it->second].insert(it->first);
        }

        for (int i = size - 1; i >= 0; i--) {
            if (sort[i].size() != 0) {
                set<string>::iterator it = sort[i].begin();
                for (; it != sort[i].end(); it++) {
                    res.push_back(*it);
                    k--;
                    if (k == 0) return res;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<string> words = {"the", "day", "is",    "sunny", "the",
                            "the", "the", "sunny", "is",    "is"};
    vector<string> res = s.topKFrequent(words, 4);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}