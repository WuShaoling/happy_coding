#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
   public:
    int FirstNotRepeatingChar(string str) {
        map<char, vector<int>> mm;

        for (int i = 0; i < str.size(); i++) {
            char c = str[i];
            if (mm.find(c) == mm.end()) {
                mm[c] = {i};
            } else {
                mm[c].push_back(i);
            }
        }

        int res = INT_MAX;
        for (map<char, vector<int>>::iterator it = mm.begin(); it != mm.end();
             it++) {
            if (it->second.size() == 1) {
                for (int i : it->second) {
                    if (i < res) res = i;
                }
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};

int main() {}