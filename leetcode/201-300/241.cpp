#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
   public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        if (input.empty()) return res;

        // 终止条件
        int num = 0;
        int i = 0;
        for (; i < input.size(); i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') break;
            num = num * 10 + input[i] - '0';
        }
        if (i == input.size()) {
            res.push_back(num);
            return res;
        }

        // 递归处理左边和右边
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                // cout << input.substr(0, i) << " " << input[i] << " "
                //      << input.substr(i + 1, input.size() - i - 1) << endl;
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(
                    input.substr(i + 1, input.size() - i - 1));
                for (int a : left) {
                    for (int b : right) {
                        res.push_back(op(a, b, input[i]));
                    }
                }
            }
        }
        return res;
    }

   private:
    int op(int n1, int n2, char op) {
        if (op == '+') {
            return n1 + n2;
        } else if (op == '-') {
            return n1 - n2;
        } else {
            return n1 * n2;
        }
    }
};

int main() {
    Solution s;
    vector<int> res = s.diffWaysToCompute("2*3-4*5");
    for (int i : res) cout << i << " ";
}