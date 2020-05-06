#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", n, 0, 0);
        return res;
    }

    void backtrack(vector<string>& res, string str, int n, int left,
                   int right) {
        if (left == n && right == n) {
            res.push_back(str);
            return;
        }
        if (left < n) backtrack(res, str + "(", n, left + 1, right);
        if (right < left) backtrack(res, str + ")", n, left, right + 1);
    }
};

int main() {}