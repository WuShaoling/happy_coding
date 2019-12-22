#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int palindromePartition(string s, int k) {
        int arr[26] = {0};
        for (char c : s) arr[c - 'a']++;
        if (s.size() == k) {
            for (int i = 0; i < 26; i++) {
                if (arr[i] > 1) return 0;
            }
        }
    }
};
int main() { Solution solution; }