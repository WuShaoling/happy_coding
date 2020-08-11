#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]
*/
class Solution {
   public:
    vector<string> restoreIpAddresses(string s) {}

    vector<string> backtrack(string s, int n) {
        if (s == "" || s.size() < 4 - n) {
            return {};
        }
    }
};

int main() {}