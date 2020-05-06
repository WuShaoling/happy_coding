#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.size();

        vector<int> rightMax(str.size());
        rightMax[n - 1] = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            if (str[i] > str[rightMax[i + 1]]) {
                rightMax[i] = i;
            } else {
                rightMax[i] = rightMax[i + 1];
            }
        }

        for (int i = 0; i < n; i++) {
            if (str[i] != str[rightMax[i]]) {
                swap(str[i], str[rightMax[i]]);
                break;
            }
        }

        return stoi(str);
    }
};

int main() {
    Solution s;
    cout << s.maximumSwap(543321);
}