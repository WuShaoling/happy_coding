#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int _max = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            if (nums[j] - nums[i] <= x) {
                _max = max(_max, j - i + 1);
            }
        }
    }
    cout << n - _max << endl;
}

// 1 2 3 3 5
// 1 2 2 3 5
// 1 2 3 4 5