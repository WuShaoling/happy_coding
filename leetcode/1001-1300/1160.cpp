#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int countCharacters(vector<string>& words, string chars) {
        int arr[26] = {0};
        for (char c : chars) arr[c - 'a']++;

        int res = 0;
        for (string word : words) {
            int temp[26] = {0};
            for (char c : word) temp[c - 'a']++;

            bool match = true;
            for (int i = 0; i < 26; i++) {
                if (arr[i] < temp[i]) {
                    match = false;
                    break;
                }
            }
            if (match) res += word.size();
        }
        return res;
    }
};

int main() {}