#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
   public:
    string removeKdigits(string num, int k) {
        if (k <= 0) return num;
        if (num.size() <= k) return "0";

        stack<char> s;
        int i = 0;
        for (; i < num.size(); i++) {
            if (s.empty() || (!s.empty() && num[i] >= s.top())) {
                s.push(num[i]);
                continue;
            }
            while (!s.empty() && s.top() > num[i] && k > 0) {
                s.pop();
                k--;
            }
            if (k <= 0) break;
            s.push(num[i]);
        }

        while (!s.empty() && k > 0) {
            s.pop();
            k--;
        }

        string res = "";
        while (!s.empty()) {
            res = s.top() + res;
            s.pop();
        }
        if (i < num.size()) res.append(num.substr(i, num.size() - i));
        i = 0;
        while (res[i] == '0') i++;
        return i == res.size() ? "0" : res.substr(i, res.size() - i);
    }
};

int main() {
    Solution s;
    cout << s.removeKdigits("1432219", 2);
}