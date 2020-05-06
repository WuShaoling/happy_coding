#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return res;
    }

   private:
    void backtrack(string temp, int left, int right, int n) {
        if (temp.length() == n * 2) {
            res.push_back(temp);
            return;
        }

        if (left < n) backtrack(temp + '(', left + 1, right, n);
        if (right < left) backtrack(temp + ')', left, right + 1, n);
    }

    vector<string> res;
};

int main() {}