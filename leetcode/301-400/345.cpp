#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string reverseVowels(string s) {
        if (s.size() == 0) return "";

        char res[s.size() + 1];
        strcpy(res, s.c_str());

        for (int i = 0, j = s.size() - 1; i < j;) {
            while (i < j && !isVowel(res[i])) i++;
            if (i >= j) break;

            while (i < j && !isVowel(res[j])) j--;
            if (i >= j) break;

            swap(res[i], res[j]);
            i++, j--;
        }

        return string(res);
    }
};

int main() {
    Solution s;
    cout << s.reverseVowels("aeiou");
}