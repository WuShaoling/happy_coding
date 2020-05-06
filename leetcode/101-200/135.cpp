#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
   public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> count(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                count[i] = count[i - 1] + 1;
            }
        }

        int ans = count[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                count[i] = max(count[i], count[i + 1] + 1);
            }
            ans += count[i];
        }

        return ans;
    }
};

/*

1 2 1 2 1 2
0 1 0 1 0 1

1 2 1 2 1
1 2 0 4 1

1 2 1
1 2 2
*/

int main() {
    Solution s;
    vector<int> nums(20001);
    for (int i = 0; i <= 20000; i++) nums[i] = i;
    cout << s.candy(nums);
}