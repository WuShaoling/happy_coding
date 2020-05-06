#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string compressString(string S) {
        if (S.size() <= 2) return S;

        int begin = 0, i = 0;
        string res = "";
        for (; i < S.size(); i++) {
            if (S[i] != S[begin]) {
                int count = i - begin;
                res += S[begin];
                res.append(to_string(count));
                if (res.size() > S.size()) return S;
                begin = i;
            }
        }
        if (i > begin) {
            int count = i - begin;
            res += S[begin];
            res.append(to_string(count));
            if (res.size() > S.size()) return S;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.compressString("abbbbb");
}