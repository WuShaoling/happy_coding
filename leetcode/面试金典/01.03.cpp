#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    string replaceSpaces(string S, int length) {
        int spaceCount = 0;
        for (int i = 0; i < length; i++) {
            if (S[i] == ' ') spaceCount++;
        }

        int j = length + spaceCount * 2 - 1;
        for (int i = length - 1; i >= 0; i--) {
            if (S[i] == ' ') {
                S[j--] = '0';
                S[j--] = '2';
                S[j--] = '%';
            } else {
                S[j--] = S[i];
            }
        }

        return S.substr(0, length + spaceCount * 2);
    }
};
// a b c
// a b c2020

int main() {
    Solution s;
    cout << s.replaceSpaces("ds sdfs afs sdfa dfssf asdf             ", 27)
         << "-";
}