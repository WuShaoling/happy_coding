#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string getPermutation(int n, int k) {
        string ans;
        string s = string("123456789").substr(0, n);
        --k;
        while (k > 0) {
            // 求第i个字符
            int i = k / fac[n - 1];
            ans.push_back(s[i]);

            // 从s中删除这个字符
            s.erase(s.begin() + i);

            k %= fac[n - 1];
            n--;
        }
        return ans + s;
    }

    const vector<int> fac = {0,   1,    2,     6,      24,     120,
                             720, 5040, 40320, 362880, 3628800};

    // string getPermutation(int n, int k) {
    //     vector<int> nums(n);
    //     vector<int> visited(n, false);
    //     for (int i = 1; i <= n; i++) {
    //         nums[i - 1] = i;
    //     }

    //     backtrack(nums, visited, n, k);

    //     string ans;
    //     for (int i : path) {
    //         ans += to_string(i);
    //     }
    //     return ans;
    // }

   private:
    bool backtrack(vector<int>& nums, vector<int>& visited, int n, int k) {
        if (path.size() == n) {
            count++;
            if (count == k) return true;
            return false;
        }

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            path.push_back(nums[i]);
            visited[i] = true;

            if (backtrack(nums, visited, n, k)) {
                return true;
            }

            visited[i] = false;
            path.pop_back();
        }

        return false;
    }

    vector<int> path;
    int count = 0;
};

int main() {
    Solution s;
    cout << s.getPermutation(3, 3);
}