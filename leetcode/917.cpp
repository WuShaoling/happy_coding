#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i = 0, j = S.size() - 1;
        while (i < j) {
            if (isalpha(S[i]) && isalpha(S[j])) {
                swap(S[i++], S[j--]);
            } else {
                if (!isalpha(S[i])) ++i;
                if (!isalpha(S[j])) --j;
            }
        }
        return S;
    }
};

int main() {
    Solution solution;
    string s = "a-b";

    cout << solution.reverseOnlyLetters(s);

    return 0;

}
