#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int m = -1, n = -1, res = INT_MAX;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) m = i;
            if (words[i] == word2) n = i;
            if (m != -1 && n != -1) {
                res = min(abs(m - n), res);
                if (res == 1) return res;
            }
        }
        return res;
    }
};

int main() {}