#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    int numberOfArrays(string s, int k) {}

    int ans = 0;
    int helper(string& s, int k, int idx) {
        if (idx == s.size()) {
            ans++;
        }
    }
};

int main() {}