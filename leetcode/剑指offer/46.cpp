#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
   public:
    int translateNum(int num) {
        string str = to_string(num);
        vector<int> dp(str.size() + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= str.size(); i++) {
            if (str[i - 2] == '1' ||
                (str[i - 2] == '2' && str[i - 1] >= '0' && str[i - 1] <= '5')) {
                dp[i] = dp[i - 1] + dp[i - 2];
            } else {
                dp[i] = dp[i - 1];
            }
        }
        // for (int i : dp) cout << dp[i] << " ";

        return dp[str.size()];
    }
};

int main() {
    Solution s;
    cout << s.translateNum(12258);
}

/*
123
012
11

 012345
 12258
 112355
*/