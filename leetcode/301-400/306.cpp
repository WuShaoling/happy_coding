#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    bool isAdditiveNumber(string num) {
        if (num.size() <= 2) return false;

        for (int j = 1; j <= num.size(); j++) {
            for (int k = j + 1; k <= num.size(); k++) {
                if (check(0, j, k, num)) {
                    return true;
                }
            }
        }
        return false;
    }

   private:
    bool check(int i, int j, int k, string &num) {
        int s1len = j - i;
        int s2len = k - j;
        int s3len = num.size() - k;

        if (num[i] == '0' && s1len > 1) return false;
        if (num[j] == '0' && s2len > 1) return false;
        if (s3len < max(s1len, s2len)) return false;

        string s1 = num.substr(i, s1len);
        string s2 = num.substr(j, s2len);
        string sum = stringAdd(s1, s2);

        if (sum.size() > s3len) return false;
        if (sum.size() == s3len) return sum == num.substr(k, sum.size());
        if (sum != num.substr(k, sum.size())) return false;
        return check(j, k, k + sum.size(), num);
    }

    string stringAdd(string s1, string s2) {
        string ans;
        int flag = 0;
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int temp = 0;
        for (; i >= 0 && j >= 0; i--, j--) {
            temp = s1[i] + s2[j] + flag - '0' - '0';
            flag = temp / 10;
            ans.push_back('0' + temp % 10);
        }
        for (; i >= 0; i--) {
            temp = s1[i] + flag - '0';
            flag = temp / 10;
            ans.push_back('0' + temp % 10);
        }
        for (; j >= 0; j--) {
            temp = s2[j] + flag - '0';
            flag = temp / 10;
            ans.push_back('0' + temp % 10);
        }
        if (flag) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution s;
    // 0235813
    // 0123456
    cout << s.isAdditiveNumber("0235813");
}