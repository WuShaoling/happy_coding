#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    string strWithout3a3b(int A, int B) {
        string ans;
        bool needSwap = (A < B);
        if (A < B) swap(A, B);
        int i = A, j = B;
        while (i > 0 && j > 0) {
            if (j > i / 2 - 1) {
                ans.push_back('a');
                ans.push_back('b');
                i--;
                j--;
            } else {
                ans.push_back('a');
                ans.push_back('a');
                ans.push_back('b');
                i -= 2;
                j--;
            }
        }
        while (i > 0) {
            ans.push_back('a');
            i--;
        }
        if (needSwap) {
            for (int i = 0; i < ans.size(); i++) {
                if (ans[i] == 'a')
                    ans[i] = 'b';
                else
                    ans[i] = 'a';
            }
        }
        return ans;
    }
};

/*

1 a  0
2 aa 0
3 aaa  1
4 aaaa 1
5 aaaaa 2
6 aaaaaa 2
7 aabaabaaba  3
8 aabaabaabaa 3
9 aabaabaabaaba   4
10 aabaabaabaabaa 4
11 aabaabaabaabaaba  5
12 aabaabaabaabaabaa 5
13 aabaabaabaabaabaaba  6
14 aabaabaabaabaabaabaa 6

aa b 1 6 bbabbabb
*/

int main() {
    Solution s;
    cout << s.strWithout3a3b(1, 3);
}